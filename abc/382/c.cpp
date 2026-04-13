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

    vector<pair<int, int>> A = {{200001, 0}};
    int a0;
    cin >> a0;
    A.push_back({a0, 1});
    for (int i=2; i!=n+1; ++i) {
        int a;
        cin >> a;
        if (a < A.back().first) {
            A.push_back({a, i});
        }
    }
    A.push_back({0, -1});
    debug(A);

    rep (_, m) {
        int b;
        cin >> b;
            
        int ng = 0;
        int ok = A.size() - 1;
        while (ok > ng + 1) {
            int mid = (ng + ok) / 2;
            if (A[mid].first > b) {
                ng = mid;
            }
            else {
                ok = mid;
            }
        }

        cout << A[ok].second << '\n';
    }

    return 0;
}