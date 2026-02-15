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

    vector<int> upper, lower;
    rep (_, q) {
        int t, x;
        cin >> t >> x;
        debug(t, x);
        if (t == 1) {
            upper.push_back(x);
        }
        else if (t == 2) {
            lower.push_back(x);
        }
        else {
            int num_upper = upper.size();
            if (x <= num_upper) {
                cout << upper[num_upper-x] << '\n'; 
            }
            else {
                cout << lower[x-num_upper-1] << '\n';
            }
        }
    }

    return 0;
}