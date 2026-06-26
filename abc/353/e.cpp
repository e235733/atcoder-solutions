#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

struct node {
    int count = 0;
    array<int, 26> nxt;
    node() {nxt.fill(-1);}
};
vector<node> trie;

int new_node() {
    trie.push_back(node());
    return (int)trie.size() - 1;
}

void make_tree (string &s, int i, int cn) {
    if (i == (int)s.size()) return ;
    int c = s[i] - 'a';
    debug(s[i], c);

    if (trie[cn].nxt[c] == -1) {
        trie[cn].nxt[c] = new_node();
    }
    int nn = trie[cn].nxt[c];
    debug(nn);
    trie[nn].count++;
    make_tree (s, i+1, nn);
}

ll ans = 0;

void dfs (int cn) {
    int c = trie[cn].count;
    ans += 1LL * c * (c - 1) / 2;
    rep (i, 26) {
        int nn = trie[cn].nxt[i];
        if (nn == -1) continue;
        dfs(nn);
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    int n;
    cin >> n;

    new_node();
    rep (_, n) {
        string s;
        cin >> s;
        make_tree(s, 0, 0);
    }

    dfs(0);

    cout << ans << '\n';

    return 0;
}