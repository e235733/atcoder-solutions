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

    int num_tree = 0;
    map<int, int> trees;

    int q;
    cin >> q;
    rep (_, q) {
        int type;
        cin >> type;

        if (type == 1) {
            int h;
            cin >> h;

            trees[h]++;
            num_tree++;
        }
        else {
            int h;
            cin >> h;

            auto it = trees.begin();
            while (it != trees.end()) {
                debug(*it);
                if (it->first > h) {
                    break;
                }
                num_tree -= it->second;
                trees.erase(it++);
            }
        }
        debug(trees);

        cout << num_tree << '\n';
    }

    return 0;
}