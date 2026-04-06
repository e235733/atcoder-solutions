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

    int x;
    cin >> x;

    int result = 0;
    for (int i=1; i!=10; ++i) {
        for (int j=1; j!=10; ++j) {
            if (i * j != x) {
                result += i * j;
            }
        }
    }
    cout << result << '\n';

    return 0;
}