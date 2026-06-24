#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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
    vector<pair<int, pair<int, int>>> aci(n);

    rep (i, n) {
        int a, c;
        cin >> a >> c;
        aci[i] = {a, {c, i+1}};
    }
    sort(aci.rbegin(), aci.rend());

    vector<int> ans;
    int pm = 1 << 30;
    rep (i, n) {
        int c = aci[i].second.first;
        int j = aci[i].second.second;

        if (c < pm) {
            ans.push_back(j);
            pm = c;
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for (int a : ans) {
        cout << a << ' ';
    }
    cout << '\n';

    return 0;
}