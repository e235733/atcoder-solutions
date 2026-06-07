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
    string s;
    cin >> n >> s;

    vector<char> W(n), D(n);
    rep (i, n) {
        switch (s[i]) {
            case 'R':
            W[i] = 'P';
            D[i] = 'R';
            break;
            case 'P':
            W[i] = 'S';
            D[i] = 'P';
            break;
            case 'S':
            W[i] = 'R';
            D[i] = 'S';
            break;
        }
    }

    int cw = 0;
    int cd = 0;
    char pw = '.';
    char pd = '.';

    rep (i, n) {
        int nw = max(
            W[i] == pw ? 0 : cw+1, 
            W[i] == pd ? 0 : cd+1
        );
        int nd = max(
            D[i] == pw ? 0 : cw, 
            D[i] == pd ? 0 : cd
        );
        cw = nw;
        cd = nd;
        pw = W[i];
        pd = D[i];

        debug(i, cw, cd);
    }

    cout << max(cw, cd) << '\n';

    return 0;
}