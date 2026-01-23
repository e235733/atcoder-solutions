#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    int n, m;
    cin >> n >> m;

    // S を2次元配列に格納
    vector<vector<char>> S(n, vector<char>(n));
    rep(i, n) {
        rep(j, n) {
            char s;
            cin >> s;

            S.at(i).at(j) = s;
        }
    }

    // T を2次元配列に格納
    vector<vector<char>> T(m, vector<char>(m));
    rep(i, m) {
        rep(j, m) {
            char t;
            cin >> t;

            T.at(i).at(j) = t;
        }
    }

    // 答えを発見したか
    bool is_found = false;

    // すべての M x M の範囲を確かめる
    // T の左上になりうるのは、S の左上から N - M + 1 まで
    rep(i, n-m+1) {
        rep(j, n-m+1) {
            //cout << "now on " << i << ' ' << j << endl;
            bool is_matched = false;
            // S の部分が T と一致しているか調べる
            rep(k, m) {
                rep(l, m) {
                    // 一致しているかどうかでフラグを変換する
                    if (S.at(i+k).at(j+l) == T.at(k).at(l)) {
                        //cout << "about " << i << ' ' << j << ", is_matched!" << endl;
                        is_matched = true;
                    }
                    // 一致していなければスキップ
                    else {
                        //cout << "about " << i << ' ' << j << ", is_not_matched!" << endl;
                        is_matched = false;
                        break;
                    }
                }
                // 一致していなければスキップ
                if (!is_matched) {
                    break;
                }
            }
            //cout << "now on " << i << ' ' << j << ", is_matched : " << is_matched << endl;
            // すべて一致していれば発見したことになる
            if (is_matched) {
                cout << i+1 << ' ' << j+1 << endl;
                is_found = true;
            }
            // すでに見つかっていればスキップ
            if (is_found) {
                break;
            }
        }
        // すでに見つかっていればスキップ
        if (is_found) {
            break;
        }
    }


    return 0;
}