#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    int t;
    cin >> t;
    rep (_, t) {
        int n, m;
        cin >> n >> m;
        vector<int> a, b;
        // a, b の総和
        ll sum = 0;
        rep (i, n) {
            int a_i;
            cin >> a_i;
            a.push_back(a_i);
            sum += a_i;
        }
        debug(a);
        rep (i, n) {
            int b_i;
            cin >> b_i;
            b.push_back(b_i);
            sum += b_i;
        }
        debug(b);
        debug(sum);

        // a を昇順に並べ、b を降順に並べる
        sort(a.begin(), a.end());
        debug(a);
        sort(b.rbegin(), b.rend());
        debug(b);

        // a_i + b_i >= m を満たす個数
        int count_over = 0;
        // b のインデックス
        int i_b = 0;
        // a を昇順に検査する
        rep (i, n) {
            // a_i + b_i >= m を満たす場合
            if (a.at(i) + b.at(i_b) >= m) {
                count_over++;
                i_b++;
            }
            // これ以上 b が存在しなければ終了
            if (i_b == n) {
                break;
            }
        }
        debug(count_over);

        // 総和から引く
        ll result = sum - 1LL * m * count_over;

        cout << result << endl;
    }

    return 0;
}