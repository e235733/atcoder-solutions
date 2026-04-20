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

    ll day = 0;
    queue<ll> trees;
    rep (_, q) {
        char type;
        cin >> type;
        debug(type);

        switch (type) {
            case '1':
            trees.push(day);

            break;
            case '2':
            ll t;
            cin >> t;
            day += t;

            break;
            case '3':
            ll h;
            cin >> h;
            int count = 0;
            while (!trees.empty()) {
                debug(day, trees.front());
                if (day - trees.front() >= h) {
                    count++;
                    trees.pop();
                }
                else {
                    break;
                }
            }
            cout << count << '\n';

            break;
        }
    }

    return 0;
}