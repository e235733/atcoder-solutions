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

    int n, m;
    cin >> n >> m;

    map<int, int> cc;
    vector<pair<int, pair<int, int>>> dab(n);
    rep (i, n) {
        int a, d, b;
        cin >> a >> d >> b;
        cc[a]++;
        dab[i] = {d, {a, b}};
    }
    debug(cc);
    debug(dab);
    sort(dab.begin(), dab.end());

    int d = 0;
    int j = 0;
    while (d != m) {
        d++;
        if (j == n) {
            cout << cc.size() << '\n';
            continue;
        }

        while (dab[j].first == d) {
            int a = dab[j].second.first;
            cc[a]--;
            if (cc[a] == 0) cc.erase(a);

            int b = dab[j].second.second;
            cc[b]++;

            j++;
            if (j == n) break;
        }

        cout << cc.size() << '\n';
    }

    return 0;
}