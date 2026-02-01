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

    int sum = 0;
    rep (i, n) {
        int a;
        cin >> a;
        // 奇数番目は、 i が偶数になるとき
        if (i % 2 == 0) {
            sum += a;
        }
    }

    cout << sum << endl;

    return 0;
}