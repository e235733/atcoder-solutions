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

    string s, t;
    cin >> s >> t;

    string not_a_s = "";
    for (char c : s) {
        if (c != 'A') {
            not_a_s += c;
        }
    }
    debug(not_a_s);
    
    string not_a_t = "";
    for (char c : t) {
        if (c != 'A') {
            not_a_t += c;
        }
    }
    debug(not_a_t);

    if (not_a_s != not_a_t) {
        cout << -1 << '\n';
        return 0;
    }

    int num_block = not_a_s.size() + 1;

    vector<int> count_a_s(num_block, 0), count_a_t(num_block, 0);
    int i = 0;
    for (char c : s) {
        if (c == 'A') {
            count_a_s[i]++;
        }
        else {
            i++;
        }
    }
    debug(count_a_s);

    int j = 0;
    for (char c : t) {
        if (c == 'A') {
            count_a_t[j]++;
        }
        else {
            j++;
        }
    }
    debug(count_a_t);

    int result = 0;
    rep (k, num_block) {
        result += abs(count_a_s[k] - count_a_t[k]);
    }
    cout << result << '\n';

    return 0;
}