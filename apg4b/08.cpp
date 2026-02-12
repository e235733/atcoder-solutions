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
        
    int p;
    cin >> p;

    // パターン1
    if (p == 1) {
        int price;
        int n;
        cin >> price >> n;
        cout << price * n << endl;
    }

    // パターン2
    if (p == 2) {
        string text;
        int price;
        int n;
        cin >> text >> price >> n;
        cout << text << "!" << endl;
        cout << price * n << endl;
    }

    return 0;
}