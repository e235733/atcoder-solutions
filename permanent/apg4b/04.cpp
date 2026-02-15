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

    // 1 年間の秒数
    int sec = 60 * 60 * 24 * 365;

    cout << sec << endl;
    cout << sec * 2 << endl;
    cout << sec * 5 << endl;
    cout << sec * 10 << endl;

    return 0;
}