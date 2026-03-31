#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

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
        int n, d;
        cin >> n >> d;

        vector<int> A(n), B(n);
        rep (i, n) {
            cin >> A[i];
        }
        rep (i, n) {
            cin >> B[i];
        }
        //debug(A, B);

        // 入荷日を記録
        queue<int> date;
        rep (i, n) {
            rep (j, A[i]) {
                date.push(i);
            }
            rep (j, B[i]) {
                date.pop();
            }
            //debug(date);
            while (!date.empty()) {
                if (date.front() > i - d) {
                    break;
                }
                date.pop();
            }
            debug(date);
        }

        cout << date.size() << '\n';
    }

    return 0;
}