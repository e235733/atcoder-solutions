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

    int t;
    cin >> t;
    rep (_, t) {
        int n;
        cin >> n;
        vector<bool> exist(n+1, false);
        vector<bool> prev_is_odd(n+1);
        bool current_is_odd = true;
        vector<int> result;
        rep (i, n*2) {
            int a;
            cin >> a;
            if (exist[a]) {
                if (prev_is_odd[a] == current_is_odd) {
                    result.push_back(i);
                    current_is_odd = !current_is_odd;
                }
            }
            else {
                exist[a] = true;
                prev_is_odd[a] = current_is_odd;
            }
        }
        cout << result.size() << '\n';
        for (int r : result) {
            cout << r << ' ';
        }
        cout << '\n';
    }

    return 0;
}