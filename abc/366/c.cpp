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

    int q;
    cin >> q;
    unordered_map<int, int> b;
    rep (_, q) {
        int t;
        cin >> t;
        switch (t) {
            case 1:
            int x;
            cin >> x;
            b[x]++;
            break;
            
            case 2:
            int y;
            cin >> y;
            b[y]--;
            if (b[y] == 0) {
                b.erase(y);
            }
            break;

            case 3:
            cout << b.size() << '\n';
            break;
        }
    }

    return 0;
}