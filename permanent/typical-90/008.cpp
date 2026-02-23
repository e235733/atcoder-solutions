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

    ll mod = 1;
    rep (_, 9) {
        mod *= 10;
    }
    mod += 7;

    int n;
    string s;
    cin >> n >> s;

    // 各文字列の作り方が何通りあるか
    ll a = 0;
    ll at = 0;
    ll atc = 0;
    ll atco = 0;
    ll atcod = 0;
    ll atcode = 0;
    ll atcoder = 0;
    
    rep (i, n) {
        char c = s[i];
        switch(c) {
            case 'a':
                a++;
                break;
            case 't':
                at = (at + a) % mod;
                break;
            case 'c':
                atc = (atc + at) % mod;
                break;
            case 'o':
                atco = (atco + atc) % mod;
                break;
            case 'd':
                atcod = (atcod + atco) % mod;
                break;
            case 'e':
                atcode = (atcode + atcod) % mod;
                break;
            case 'r':
                atcoder = (atcoder + atcode) % mod;
                break;
        }
    }

    cout << atcoder << '\n';

    return 0;
}