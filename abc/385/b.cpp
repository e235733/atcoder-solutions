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

    int h, w, x, y;
    cin >> h >> w >> x >> y;
    x--;
    y--;
    debug(x, y);

    vector<string> S(h);
    rep (i, h){
        cin >> S[i];
    }

    string t;
    cin >> t;

    set<pair<int, int>> houses;
    for (char d : t) {
        debug(d);
        switch (d) {
            case 'U':
                if (S[x-1][y] != '#') {
                    x--;
                }
                break;
            case 'D':
                if (S[x+1][y] != '#') {
                    x++;
                }
                break;
            case 'L':
                if (S[x][y-1] != '#') {
                    y--;
                }
                break;
            case 'R':
                if (S[x][y+1] != '#') {
                    y++;
                }
                break;
        }
        debug(x, y, S[x][y]);
        if (S[x][y] == '@') {
            houses.insert({x, y});
        }
    }
    debug(houses);

    cout << x + 1 << ' ' << y + 1 << ' ' << houses.size() << '\n';

    return 0;
}