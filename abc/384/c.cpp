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

    vector<int> scores(5);
    rep (i, 5) {
        cin >> scores[i];
    }

    string all = "ABCDE";
    map<int, vector<string>> result;
    for (int i=1; i!=32; ++i) {
        int left = i;
        int score = 0;
        string name = "";
        rep (j, 5) {
            if (left % 2 == 1) {
                score += scores[j];
                name += all[j];
            }
            left /= 2;
        }
        debug(name, score);
        result[score].push_back(name);
    }
    debug(result);

    auto it = result.rbegin();
    while (it != result.rend()) {
        vector<string> names = it->second;
        sort(names.begin(), names.end());
        for (string n : names) {
            cout << n << '\n';
        }
        ++it;
    }

    return 0;
}