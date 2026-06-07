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

    vector<pair<int, int>> A(n);
    rep (i, n) {
        int a;
        cin >> a;

        A[i] = {a, i+1};
    }
    sort(A.rbegin(), A.rend());

    cout << A[1].second << '\n';

    return 0;
}