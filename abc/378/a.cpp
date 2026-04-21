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

    map<int, int> colors;
    rep (_, 4) {
        int a;
        cin >> a;

        colors[a]++;
    }

    int count = 0;
    for (auto c : colors) {
        count += c.second / 2;
    }

    cout << count << '\n';

    return 0;
}