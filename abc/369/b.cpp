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
    cin >> n;

    int pl = -1;
    int pr = -1;
    int count = 0;
    rep (_, n) {
        int a;
        char s;
        cin >> a >> s;

        if (s == 'L') {
            if (pl == -1) {
                pl = a;
                continue;
            }

            count += abs(a - pl);
            pl = a;
        }
        else if (s == 'R'){
            if (pr == -1) {
                pr = a;
                continue;
            }

            count += abs(a - pr);
            pr = a;
        }
    }

    cout << count << '\n';

    return 0;
}