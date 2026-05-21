#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

void all_search(vector<int> &k, int a, int b, int i, int n, int &min_max) {
    if (i == n) {
        min_max = min(min_max, max(a, b));
        debug(min_max);
        return;
    }

    debug(i, a, b);
    all_search(k, a+k[i], b, i+1, n, min_max);
    all_search(k, a, b+k[i], i+1, n, min_max);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    int n;
    cin >> n;
    vector<int> k(n);
    rep (i, n) {
        cin >> k[i];
    }

    int min_max = 2000000000;
    all_search(k, 0, 0, 0, n, min_max);
    cout << min_max << '\n';

    return 0;
}