#include <bits/stdc++.h>
#include <random>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

// タイマー管理用クラス
struct Timer {
    chrono::high_resolution_clock::time_point start_time;
    Timer() { start_time = chrono::high_resolution_clock::now(); }
    double get_time() {
        auto now = chrono::high_resolution_clock::now();
        return chrono::duration<double>(now - start_time).count();
    }
};

int N, M, T;
vector<vector<int>> G; // 隣接リスト

int to_id(int r, int c) { return r * N + c; }

// 重い多次元配列をグローバル領域に配置（Bus Error対策）
int global_dist[405][4];
int global_prev_node[405][4];
int global_prev_dir[405][4];

// 拡張BFS / ダイクストラ法
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

// 経路復元
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
        if (nxt_node == -1) break;
        cur_node = nxt_node;
        cur_dir = nxt_dir;
    }
    path.push_back(start_node);
    reverse(path.begin(), path.end());
    return path;
}

// 純粋に生の操作文字列（F, R, L）だけを生成する安全な関数
string simulate_path_raw(const vector<int>& path, int& robot_pos, int& robot_dir) {
    string actions = "";
    if (path.size() <= 1) return actions;

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
                for (int c = 0; c < r_cost; ++c) actions += 'R';
            } else {
                for (int c = 0; c < l_cost; ++c) actions += 'L';
            }
            robot_dir = target_dir;
        }
        actions += 'F';
        robot_pos = next_node;
    }
    return actions;
}

// 順番から「生の操作文字列（マクロなし）」を復元する評価関数
string evaluate_order_raw(const vector<int>& order, const vector<int>& ball_pos, const vector<int>& basket_pos) {
    string total_actions = "";
    int r_pos = to_id(0, 0);
    int r_dir = 0;

    for (int ball_idx : order) {
        compute_optimal_bfs(r_pos, r_dir);
        vector<int> path_to_ball = reconstruct_optimal_path(r_pos, ball_pos[ball_idx]);
        total_actions += simulate_path_raw(path_to_ball, r_pos, r_dir);
        total_actions += 'S';

        compute_optimal_bfs(r_pos, r_dir);
        vector<int> path_to_basket = reconstruct_optimal_path(r_pos, basket_pos[ball_idx]);
        total_actions += simulate_path_raw(path_to_basket, r_pos, r_dir);
        total_actions += 'S';
    }
    return total_actions;
}

// ★【高速数理モデル】直線が f_count 連続した時、マクロ（1重・2重）を適用した後の最小コストを O(1) で割り出す
int get_macro_straight_cost(int f_count) {
    if (f_count < 5) return f_count;
    int best_cost = f_count; // マクロ不使用時

    // 1重マクロを想定したコスト
    int k = f_count / 2;
    int rem1 = f_count - (k * 2);
    int cost1 = 1 + k + 1 + 1 + rem1; // M + F*k + M + P + F*rem1
    best_cost = min(best_cost, cost1);

    // 2重マクロを想定したコスト
    if (f_count >= 10) {
        for (int K = 1; K <= 10; ++K) {
            for (int R = 1; R <= 10; ++R) {
                int moved = 1 + K * (R + 1);
                if (moved > f_count) continue;
                int rem2 = f_count - moved;
                int cost2 = 1 + 1 + 1 + 1 + K + 1 + R + rem2; // M + F + M + M + P*K + M + P*R + F*rem2
                best_cost = min(best_cost, cost2);
            }
        }
    }
    return best_cost;
}

// ★【新・評価関数】山登り法の中で何万回も呼ばれる、マクロ適用後を「超高速に予測する」関数
int evaluate_order_estimated(const vector<int>& order, const vector<int>& ball_pos, const vector<int>& basket_pos) {
    int total_cost = 0;
    int r_pos = to_id(0, 0);
    int r_dir = 0;

    for (int ball_idx : order) {
        // ① ボールへ移動
        compute_optimal_bfs(r_pos, r_dir);
        vector<int> path_to_ball = reconstruct_optimal_path(r_pos, ball_pos[ball_idx]);
        if (path_to_ball.size() > 1) {
            vector<int> dirs;
            for (size_t i = 0; i < path_to_ball.size() - 1; ++i) {
                int cur = path_to_ball[i]; int next_node = path_to_ball[i+1];
                int target_dir = -1;
                if (next_node == cur + 1) target_dir = 0;
                if (next_node == cur + N) target_dir = 1;
                if (next_node == cur - 1) target_dir = 2;
                if (next_node == cur - N) target_dir = 3;
                dirs.push_back(target_dir);
            }
            size_t idx = 0;
            while (idx < dirs.size()) {
                int target_dir = dirs[idx];
                if (r_dir != target_dir) {
                    int r_cost = (target_dir - r_dir + 4) % 4;
                    int l_cost = (r_dir - target_dir + 4) % 4;
                    total_cost += min(r_cost, l_cost);
                    r_dir = target_dir;
                }
                size_t f_count = 0;
                while (idx + f_count < dirs.size() && dirs[idx + f_count] == r_dir) f_count++;
                total_cost += get_macro_straight_cost(f_count); // 予測式を適用
                idx += f_count;
            }
            r_pos = path_to_ball.back();
        }
        total_cost += 1; // S

        // ② かごへ移動
        compute_optimal_bfs(r_pos, r_dir);
        vector<int> path_to_basket = reconstruct_optimal_path(r_pos, basket_pos[ball_idx]);
        if (path_to_basket.size() > 1) {
            vector<int> dirs;
            for (size_t i = 0; i < path_to_basket.size() - 1; ++i) {
                int cur = path_to_basket[i]; int next_node = path_to_basket[i+1];
                int target_dir = -1;
                if (next_node == cur + 1) target_dir = 0;
                if (next_node == cur + N) target_dir = 1;
                if (next_node == cur - 1) target_dir = 2;
                if (next_node == cur - N) target_dir = 3;
                dirs.push_back(target_dir);
            }
            size_t idx = 0;
            while (idx < dirs.size()) {
                int target_dir = dirs[idx];
                if (r_dir != target_dir) {
                    int r_cost = (target_dir - r_dir + 4) % 4;
                    int l_cost = (r_dir - target_dir + 4) % 4;
                    total_cost += min(r_cost, l_cost);
                    r_dir = target_dir;
                }
                size_t f_count = 0;
                while (idx + f_count < dirs.size() && dirs[idx + f_count] == r_dir) f_count++;
                total_cost += get_macro_straight_cost(f_count); // 予測式を適用
                idx += f_count;
            }
            r_pos = path_to_basket.back();
        }
        total_cost += 1; // S
    }
    return total_cost;
}

// あらゆるリピートコンボを1重・2重マクロへ昇華させる全自動圧縮パーサ（最後の1回だけ実行）
string super_compress(const string& s) {
    string res = "";
    int i = 0; int n = s.size();

    while (i < n) {
        int best_saved = 0; int best_len = 0; int best_count = 0; int best_type = 0;
        int best_K = 0, best_R = 0, best_rem = 0;

        for (int len = 1; len <= 15; ++len) {
            if (i + len > n) break;
            string pattern = s.substr(i, len);
            int count = 0;
            while (i + count * len + len <= n && s.substr(i + count * len, len) == pattern) count++;
            if (count == 0) continue;

            for (int c = 1; c <= count; ++c) {
                int raw_cost = len * c;
                int cost1 = 1 + len + 1 + (c - 1);
                int saved1 = raw_cost - cost1;
                if (saved1 > best_saved) {
                    best_saved = saved1; best_len = len; best_count = c; best_type = 1;
                }
                for (int K = 1; K <= 10; ++K) {
                    for (int R = 1; R <= 10; ++R) {
                        int moved = 1 + K * (R + 1);
                        if (moved > c) continue;
                        int rem = c - moved;
                        int cost2 = 1 + len + 1 + 1 + K + 1 + R + rem * len;
                        int saved2 = raw_cost - cost2;
                        if (saved2 > best_saved) {
                            best_saved = saved2; best_len = len; best_count = c; best_type = 2;
                            best_K = K; best_R = R; best_rem = rem;
                        }
                    }
                }
            }
        }

        if (best_saved > 0) {
            string pattern = s.substr(i, best_len);
            if (best_type == 1) {
                res += 'M' + pattern + 'M';
                rep(j, best_count - 1) res += 'P';
            } else if (best_type == 2) {
                res += 'M' + pattern + 'M'; 
                res += 'M'; rep(j, best_K) res += 'P'; res += 'M'; 
                rep(j, best_R) res += 'P'; 
                rep(j, best_rem) res += pattern; 
            }
            i += best_len * best_count;
        } else {
            res += s[i]; i++;
        }
    }
    return res;
}

int main() {
    Timer timer; 
    mt19937 rng(42); 

    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    if (!(cin >> N >> M >> T)) return 0;
    G.resize(N * N);

    // 壁の読み込み
    for (int i = 0; i < N; ++i) {
        string v; cin >> v;
        for (int j = 0; j < N - 1; ++j) {
            if (v[j] == '0') {
                G[to_id(i, j)].push_back(to_id(i, j + 1));
                G[to_id(i, j + 1)].push_back(to_id(i, j));
            }
        }
    }
    for (int i = 0; i < N - 1; ++i) {
        string h; cin >> h;
        for (int j = 0; j < N; ++j) {
            if (h[j] == '0') {
                G[to_id(i, j)].push_back(to_id(i + 1, j));
                G[to_id(i + 1, j)].push_back(to_id(i, j));
            }
        }
    }

    // ボールとかごの位置
    vector<int> ball_pos(M), basket_pos(M);
    rep (i, M) {
        int b, c, d, e;
        cin >> b >> c >> d >> e;
        ball_pos[i] = to_id(b, c);
        basket_pos[i] = to_id(d, e);
    }

    // 1. 【初期解の構築】強固なダイクストラ貪欲
    vector<int> current_order;
    vector<bool> target_done(M, false);
    int r_pos = to_id(0, 0); int r_dir = 0;

    rep(step, M) {
        compute_optimal_bfs(r_pos, r_dir);
        int min_cost = 1e9; int next_ball_idx = -1;
        rep(i, M) {
            if (target_done[i]) continue;
            int current_cost = 1e9;
            rep(d, 4) current_cost = min(current_cost, global_dist[ball_pos[i]][d]);
            if (current_cost < min_cost) { min_cost = current_cost; next_ball_idx = i; }
        }
        if (next_ball_idx == -1) break;
        current_order.push_back(next_ball_idx);
        target_done[next_ball_idx] = true;

        vector<int> path_to_ball = reconstruct_optimal_path(r_pos, ball_pos[next_ball_idx]);
        simulate_path_raw(path_to_ball, r_pos, r_dir);
        compute_optimal_bfs(r_pos, r_dir);
        vector<int> path_to_basket = reconstruct_optimal_path(r_pos, basket_pos[next_ball_idx]);
        simulate_path_raw(path_to_basket, r_pos, r_dir);
    }

    // 初期スコア（予測値）の計算
    int best_estimated_score = evaluate_order_estimated(current_order, ball_pos, basket_pos);

    // 2. 【山登り法メインループ】
    // 評価関数が超軽量化されたため、1.95秒間で何万回もハイスピードでスワップが回ります
    int iterations = 0;
    while (timer.get_time() < 1.95) {
        iterations++;

        int idx1 = rng() % M;
        int idx2 = rng() % M;
        if (idx1 == idx2) continue;

        swap(current_order[idx1], current_order[idx2]);

        // ★マクロの仕上がりを予測したスコアで評価！
        int new_estimated_score = evaluate_order_estimated(current_order, ball_pos, basket_pos);

        if (new_estimated_score <= best_estimated_score) {
            best_estimated_score = new_estimated_score;
        } else {
            swap(current_order[idx1], current_order[idx2]); // ロールバック
        }
    }

    debug("山登りループ回数:", iterations);
    debug("山登り法による予測最小手数:", best_estimated_score);

    // 3. 【最終出力用の生文字列を復元 ＆ 本番圧縮】
    // 選び抜かれた最強の順番から、一度ピュアな操作列を復元する
    string best_raw_actions = evaluate_order_raw(current_order, ball_pos, basket_pos);
    debug("圧縮前のピュア手数:", best_raw_actions.size());

    // 最後に1回だけ、本物の最強圧縮をかける
    string ans_actions = super_compress(best_raw_actions);

    // 4. 【行単位での出力】
    if (ans_actions.size() > (size_t)T) {
        ans_actions = ans_actions.substr(0, T);
    }
    for (char c : ans_actions) {
        cout << c << '\n';
    }
    debug("多重マクロ圧縮後の最終手数:", ans_actions.size());

    return 0;
}