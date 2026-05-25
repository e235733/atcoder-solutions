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

    int t;
    cin >> t;
    rep (_, t) {
        string s;
        cin >> s;

        int len = s.size();
        debug(s, len);
        if (len == 1) {
            cout << "Yes\n" << s << '\n';
            continue;
        }

        unordered_map<char, int> count;
        rep (i, len) {
            count[s[i]]++;
        }

        vector<pair<int, char>> sc;
        for (auto p : count) {
            sc.push_back({p.second, p.first});
        }
        sort(sc.begin(), sc.end());
        debug(sc);

        if (sc.back().first > (len+1)/2) {
            cout << "No" << '\n';
            continue;
        }

        cout << "Yes" << '\n';

        vector<char> fewer;
        fewer.reserve(len);
        for (pair<int, char> p : sc) {
            rep (i, p.first) {
                fewer.push_back(p.second);
            }
        }
        debug(fewer);

        vector<char> result(len);
        rep (i, len/2) {
            result[i*2+1] = fewer[i];
        }
        rep (i, len-len/2) {
            result[i*2] = fewer[i+len/2];
        }
        
        rep (i, len) {
            cout << result[i];
        }
        cout << '\n';
    }

    return 0;
}