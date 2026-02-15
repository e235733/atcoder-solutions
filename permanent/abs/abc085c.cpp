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

    int n, y;
    cin >> n >> y;

    // 一直線上に n 枚の札を並べるのを考える。最初は全部 1000円札
    // ５０００円札の始まり
    for (int i=1; i!=n+2; ++i) {
        // １０００円札の始まり
        for (int j=i; j!=n+2; ++j) {
            int num10000 = i - 1;
            int num5000 = j - i;
            int num1000 = n + 1 - j;
            int value = 10000 * (num10000) + 5000 * (num5000) + 1000 * (num1000);
            if (value == y) {
                cout << num10000 << ' ' << num5000 << ' ' << num1000 << endl;
                return 0;
            }
        }
    }
    cout << -1 << ' ' << -1 << ' ' << -1 << endl;
    
    return 0;
}