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

    int n, k;
    cin >> n >> k;
    debug(n, k);
    vector<int> A(n);
    rep (i, n) {
        cin >> A[i];
    }

    // 最小の操作回数を求める
    int min_op = 0;
    rep (i, n) {
        int b;
        cin >> b;
        min_op += abs(b - A[i]);
    }
    debug(min_op);

    // k が最小回数より大きいか
    if (k < min_op) {
        cout << "No" << endl;
        return 0;
    }

    // k と min_op の差が偶数か
    int diff = k - min_op;
    if (diff % 2 == 0) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    return 0;
}