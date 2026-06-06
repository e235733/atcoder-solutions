#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

int N, M, T;
vector<vector<int>> G; // 隣接リスト

// マス(r, c) を 1次元IDに変換
int to_id(int r, int c) { return r * N + c; }

// 構造体：ターゲットのID、そこまでの最小操作コスト、および移動経路を保持する
struct TargetInfo {
    int id;               // ボール（またはかご）の識別番号 (0 ～ M-1)
    int distance;         // そこまでの最小操作コスト（前進 + 回転の合計）
    vector<int> path;     // そこまでの移動経路（マスIDのリスト）
};

// 重い多次元配列をグローバル領域に配置（Bus Error / スタックオーバーフロー対策）
int global_dist[405][4];
int global_prev_node[405][4];
int global_prev_dir[405][4];

// 始点(start_node)に、指定 of 向き(start_dir)で立っている状態からの、全マスへの最短操作コストを計算する（拡張BFS / ダイクストラ法）
void compute_optimal_bfs(int start_node, int start_dir) {
    rep(i, N * N) rep(d, 4) {
        global_dist[i][d] = 1e9;
        global_prev_node[i][d] = -1;
        global_prev_dir[i][d] = -1;
    }

    using P = pair<int, pair<int, int>>;
    priority_queue<P, vector<P>, greater<P>> pq;

    global_dist[start_node][start_dir] = 0;
    pq.push({0, {start_node, start_dir}});

    while (!pq.empty()) {
        auto [d, state] = pq.top();
        pq.pop();
        int cur_node = state.first;
        int cur_dir = state.second;

        if (d > global_dist[cur_node][cur_dir]) continue;

        for (int next_node : G[cur_node]) {
            int nxt_dir = -1;
            if (next_node == cur_node + 1) nxt_dir = 0; // 右
            if (next_node == cur_node + N) nxt_dir = 1; // 下
            if (next_node == cur_node - 1) nxt_dir = 2; // 左
            if (next_node == cur_node - N) nxt_dir = 3; // 上

            int r_cost = (nxt_dir - cur_dir + 4) % 4;
            int l_cost = (cur_dir - nxt_dir + 4) % 4;
            int turn_cost = min(r_cost, l_cost);

            int cost = 1 + turn_cost;

            if (global_dist[cur_node][cur_dir] + cost < global_dist[next_node][nxt_dir]) {
                global_dist[next_node][nxt_dir] = global_dist[cur_node][cur_dir] + cost;
                global_prev_node[next_node][nxt_dir] = cur_node;
                global_prev_dir[next_node][nxt_dir] = cur_dir;
                pq.push({global_dist[next_node][nxt_dir], {next_node, nxt_dir}});
            }
        }
    }
}

// グローバル配列の結果から、ゴールマスに到達したときの最適な経路を復元する関数
vector<int> reconstruct_optimal_path(int start_node, int goal_node) {
    if (start_node == goal_node) return {start_node};

    int best_dir = 0;
    int min_cost = 1e9;
    for (int d = 0; d < 4; ++d) {
        if (global_dist[goal_node][d] < min_cost) {
            min_cost = global_dist[goal_node][d];
            best_dir = d;
        }
    }

    vector<int> path;
    int cur_node = goal_node;
    int cur_dir = best_dir;

    while (cur_node != start_node) {
        path.push_back(cur_node);
        int nxt_node = global_prev_node[cur_node][cur_dir];
        int nxt_dir = global_prev_dir[cur_node][cur_dir];
        
        if (nxt_node == -1) {
            debug("経路復元エラー: 親が見つかりません", start_node, goal_node, cur_node);
            break;
        }

        cur_node = nxt_node;
        cur_dir = nxt_dir;
    }
    path.push_back(start_node);
    reverse(path.begin(), path.end());
    return path;
}

// ★【新機能】基本操作の文字列から、5連続以上の直進（F）をマクロ（M, P）に一括圧縮する関数
string compress_actions_with_macro(const string& raw_actions) {
    string compressed = "";
    int i = 0;
    int len = raw_actions.size();

    while (i < len) {
        // F の連続数をカウントする
        if (raw_actions[i] == 'F') {
            int f_count = 0;
            while (i + f_count < len && raw_actions[i + f_count] == 'F') {
                f_count++;
            }

            // マクロを使った方が得になる閾値（5連続以上の場合に圧縮）
            // マクロのオーバーヘッド（M, M, P）で3手使うため、5マスなら M FF M P + F = 6手（1手得）
            if (f_count >= 5) {
                int k = f_count / 2; // マクロに記録する歩数
                int rem = f_count - (k * 2); // 余りの歩数（0 または 1）

                compressed += 'M'; // マクロ記録開始
                rep(j, k) compressed += 'F';
                compressed += 'M'; // マクロ記録終了
                compressed += 'P'; // マクロ再生（これで k * 2 歩進む）
                rep(j, rem) compressed += 'F'; // 余った1歩があれば普通に進む
            } else {
                // 4連続以下ならマクロを使わずそのまま足す
                rep(j, f_count) compressed += 'F';
            }
            i += f_count;
        } else {
            // R, L, S などの基本操作はそのままスルー
            compressed += raw_actions[i];
            i++;
        }
    }
    return compressed;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    // 1. 【入力処理】
    debug("--- Step 1: 入力開始 ---");
    if (!(cin >> N >> M >> T)) {
        debug("入力エラー: N, M, T が読み込めません");
        return 0;
    }
    G.resize(N * N);

    // ① 横方向の壁を読み込む
    for (int i = 0; i < N; ++i) {
        string v; cin >> v;
        for (int j = 0; j < N - 1; ++j) {
            if (v[j] == '0') {
                G[to_id(i, j)].push_back(to_id(i, j + 1));
                G[to_id(i, j + 1)].push_back(to_id(i, j));
            }
        }
    }
    // ② 縦方向の壁を読み込む
    for (int i = 0; i < N - 1; ++i) {
        string h; cin >> h;
        for (int j = 0; j < N; ++j) {
            if (h[j] == '0') {
                G[to_id(i, j)].push_back(to_id(i + 1, j));
                G[to_id(i + 1, j)].push_back(to_id(i, j));
            }
        }
    }

    // ③ ボールとかごの位置を読み込む
    vector<int> ball_pos(M), basket_pos(M);
    rep (i, M) {
        int b, c, d, e;
        cin >> b >> c >> d >> e;
        ball_pos[i] = to_id(b, c);
        basket_pos[i] = to_id(d, e);
    }
    debug("入力完了。全マス数:", N * N, "ボール数:", M);


    // 2. 【前処理】スタート地点(0,0)・右向き(0)からの最初の一歩だけ計算
    debug("--- Step 2: 前処理開始 ---");
    vector<TargetInfo> from_start(M);
    {
        compute_optimal_bfs(to_id(0, 0), 0); 
        for (int i = 0; i < M; ++i) {
            int min_d = 1e9;
            for(int d = 0; d < 4; ++d) min_d = min(min_d, global_dist[ball_pos[i]][d]);
            from_start[i] = {i, min_d, reconstruct_optimal_path(to_id(0, 0), ball_pos[i])};
        }
        sort(from_start.begin(), from_start.end(), [](const TargetInfo& a, const TargetInfo& b) {
            return a.distance < b.distance;
        });
    }
    debug("最初の一歩の計算完了");


    // 3. 【シミュレーション（お片付けルート生成）】
    debug("--- Step 3: シミュレーション開始 ---");
    string raw_actions = ""; // 一旦マクロなしの生の操作を溜める
    int robot_pos = to_id(0, 0); 
    int robot_dir = 0;           
    vector<bool> target_done(M, false); 

    // パスをたどってロボットを移動・回転させるヘルパー関数
    auto execute_move = [&](const vector<int>& path) {
        for (size_t i = 0; i < path.size() - 1; ++i) {
            int cur = path[i];
            int next_node = path[i+1];
            int target_dir = -1;
            if (next_node == cur + 1) target_dir = 0; 
            if (next_node == cur + N) target_dir = 1; 
            if (next_node == cur - 1) target_dir = 2; 
            if (next_node == cur - N) target_dir = 3; 

            if (robot_dir != target_dir) {
                int r_cost = (target_dir - robot_dir + 4) % 4;
                int l_cost = (robot_dir - target_dir + 4) % 4;
                if (r_cost <= l_cost) {
                    for (int c = 0; c < r_cost; ++c) raw_actions += 'R';
                } else {
                    for (int c = 0; c < l_cost; ++c) raw_actions += 'L';
                }
                robot_dir = target_dir;
            }
            raw_actions += 'F';
            robot_pos = next_node;
        }
    };

    bool is_first_step = true;

    for (int step = 0; step < M; ++step) {
        int next_ball_idx = -1;
        vector<int> path_to_ball;

        if (is_first_step) {
            for (const auto& info : from_start) {
                if (!target_done[info.id]) {
                    next_ball_idx = info.id;
                    path_to_ball = info.path;
                    break;
                }
            }
            is_first_step = false;
        } else {
            compute_optimal_bfs(robot_pos, robot_dir);
            int min_cost = 1e9;
            for (int i = 0; i < M; ++i) {
                if (target_done[i]) continue;
                
                int current_cost = 1e9;
                for (int d = 0; d < 4; ++d) current_cost = min(current_cost, global_dist[ball_pos[i]][d]);

                if (current_cost < min_cost) {
                    min_cost = current_cost;
                    next_ball_idx = i;
                }
            }
            if (next_ball_idx != -1) {
                path_to_ball = reconstruct_optimal_path(robot_pos, ball_pos[next_ball_idx]);
            }
        }

        if (next_ball_idx == -1) break;

        // ① ボールの位置まで移動して拾う (S)
        execute_move(path_to_ball);
        raw_actions += 'S';

        // ② 対応するかごの位置まで移動して置く (S)
        compute_optimal_bfs(robot_pos, robot_dir);
        vector<int> path_to_basket = reconstruct_optimal_path(robot_pos, basket_pos[next_ball_idx]);
        
        execute_move(path_to_basket);
        raw_actions += 'S';

        target_done[next_ball_idx] = true;
    }


    // 4. 【マクロ圧縮と行単位での結果出力】
    debug("--- Step 4: マクロ圧縮と結果出力 ---");
    
    // 生成したすべての操作列から、長い直線をマクロに置き換える！
    string ans_actions = compress_actions_with_macro(raw_actions);
    

    if (ans_actions.size() > (size_t)T) {
        ans_actions = ans_actions.substr(0, T);
    }
    
    // 1文字（1操作）ごとに改行して出力
    for (char c : ans_actions) {
        cout << c << '\n';
    }
    debug("圧縮前の総操作数:", raw_actions.size());
    debug("圧縮後の最終操作数:", ans_actions.size());

    return 0;
}