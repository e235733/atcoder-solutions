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

    string s;
    cin >> s;

    unordered_map<char, int> counts;
    int max_count = 0;

    for (char c : s) {
        counts[c]++;
        max_count = max(counts[c], max_count);
    }
    debug(counts);
    debug(max_count);

    for (char c : s) {
        if (counts[c] != max_count) {
            cout << c;
        }
    }
    cout << '\n';

    return 0;
}