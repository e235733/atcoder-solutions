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
    unordered_map<int, int> count;

    rep (_, n) {
        int a;
        cin >> a;
        count[a]++;
    }

    int max_a;
    int max_count = 0;
    for (auto c : count) {
        if (c.second > max_count) {
            max_a = c.first;
            max_count = c.second;
        }
    }

    cout << max_a << ' ' << max_count << endl;

    return 0;
}