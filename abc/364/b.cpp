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

    int h, w, si, sj;
    cin >> h >> w >> si >> sj;
    int r = si - 1;
    int c = sj - 1;

    vector<string> C(h);
    rep (i, h) cin >> C[i];

    string x;
    cin >> x;

    for (char d : x) {
        switch (d) {
            case 'U':
            if (r <= 0) continue;
            if (C[r-1][c] == '#') continue;
            r--;
            break;
            case 'D':
            if (r >= h-1) continue;
            if (C[r+1][c] == '#') continue;
            r++;
            break;
            case 'L':
            if (c <= 0) continue;
            if (C[r][c-1] == '#') continue;
            c--;
            break;
            case 'R':
            if (c >= w-1) continue;
            if (C[r][c+1] == '#') continue;
            c++;
            break;
        }
    }

    cout << r + 1 << ' ' << c + 1 << '\n';

    return 0;
}