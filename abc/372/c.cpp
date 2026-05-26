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

    int n, q;
    string s;
    cin >> n >> q >> s;
    
    int count = 0;
    rep (i, n-2) {
        if (s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C') {
            count++;
        }
    }

    rep (i, q) {
        int x;
        char c;
        cin >> x >> c;

        rep (j, 3) {
            if (x-3+j >= 0 && x-1+j < n) {
                if (s[x-3+j] == 'A' && s[x-2+j] == 'B' && s[x-1+j] == 'C') {
                    count--;
                }
            }
        }
        s[x-1] = c;
        rep (j, 3) {
            if (x-3+j >= 0 && x-1+j < n) {
                if (s[x-3+j] == 'A' && s[x-2+j] == 'B' && s[x-1+j] == 'C') {
                    count++;
                }
            }
        }

        cout << count << '\n';
    }

    return 0;
}