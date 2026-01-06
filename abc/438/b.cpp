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

    string s, t;
    cin >> s >> t;

    // 全探査する。まずは長さを求め、探査すべきSの部分文字列の数を特定する。
    int len_s = s.size();
    int len_t = t.size();
    int num_sub = len_s - len_t + 1;

    // 全ての部分文字列を調べ、最小値を探す
    int min_diff = 9 * len_t;
    rep(i, num_sub) {
        string sub_s = s.substr(i, len_t);
        // cout << sub_s << endl;
        
        // 各文字ごとにs-tの値を求め合計する
        int sum_diff = 0;
        rep(i, len_t) {
            int s_v = sub_s.at(i) - '0';
            int t_v = t.at(i) - '0';

            int diff = s_v - t_v;
            if (diff < 0) {
                diff += 10;
            }

            sum_diff += diff;
        }
        //cout << sum_diff << endl;

        min_diff = min(min_diff, sum_diff);
    }

    cout << min_diff << endl;

    return 0;
}