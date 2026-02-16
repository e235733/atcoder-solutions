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

    int n;
    cin >> n;

    //　ソートされた a のリストを作成
    vector<int> A(n);
    rep (i, n) cin >> A[i];
    sort(A.begin(), A.end());
    debug(A);

    int q;
    cin >> q;
    rep (_, q) {
        int b;
        cin >> b;
        debug(b);
        // 自力で2分探索を実装してみる
        int left = 0;
        int right = n - 1;
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            if (A[mid] >= b) {
                right = mid;
            }
            else {
                left = mid;
            }
            debug(left, right);
        }
        // 差が小さい方を加算
        int min_sum = min(abs(A[left] - b), abs(A[right] - b));
        cout << min_sum << '\n';
    }

    return 0;
}