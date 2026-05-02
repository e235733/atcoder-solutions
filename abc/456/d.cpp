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

    string s;
    cin >> s;

    int length = s.size();

    vector<ll> a(length+1, 0), b(length+1, 0), c(length+1, 0);
    rep (i, length) {
        switch (s[i]) {
            case 'a':
            a[i+1] = a[i] + b[i] + c[i] + 1;
            a[i+1] %= 998244353;
            b[i+1] = b[i];
            c[i+1] = c[i];
            break;
            case 'b':
            b[i+1] = b[i] + a[i] + c[i] + 1;
            b[i+1] %= 998244353;
            a[i+1] = a[i];
            c[i+1] = c[i];
            break;
            case 'c':
            c[i+1] = c[i] + a[i] + b[i] + 1;
            c[i+1] %= 998244353;
            a[i+1] = a[i];
            b[i+1] = b[i];
            break;
        }
        //debug(a);
        //debug(b);
        //debug(c);
    }

    cout << (a[length] + b[length] + c[length]) % 998244353 << '\n';

    return 0;
}