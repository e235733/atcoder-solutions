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

    int n, m;
    cin >> n >> m;
    
    unordered_set<int> clothes;
    bool is_ok = true;

    vector<bool> used(m+1, false);
    rep (i, n) {
        int f;
        cin >> f;

        if (is_ok) {
            if (clothes.contains(f)) {
                cout << "No" << '\n';
                is_ok = false;
            }
            else {
                clothes.insert(f);
            }
        }
        used[f] = true;
    }
    if (is_ok) {
        cout << "Yes" << '\n';
    }

    for (int i=1; i!=m+1; ++i) {
        if (!used[i]) {
            cout << "No" << '\n';
            return 0;
        }
    }
    cout << "Yes" << '\n';

    return 0;
}