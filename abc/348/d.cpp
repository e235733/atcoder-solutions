#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

vector<int> dr = {-1, 1, 0, 0};
vector<int> dc = {0, 0, 1, -1};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    int h, w;
    cin >> h >> w;
    vector<string> S(h);
    rep (i, h) cin >> S[i];

    int si = -1;
    int ti = -1;
    vector<vector<int>> G(h*w+1);
    rep (i, h) {
        rep (j, w) {
            if (S[i][j] == '#') continue;

            if (S[i][j] == 'S') {
                si = i * w + j;
            }
            else if (S[i][j] == 'T') {
                ti = i * w + j;
            }

            rep (k, 4) {
                int nr = i + dr[k];
                int nc = j + dc[k];

                if (nr == -1 || nr == h || nc == -1 || nc == w) continue;
                if (S[nr][nc] == '#') continue;

                G[i*w+j].push_back(nr*w+nc);
            }
        }
    }

    int n;
    cin >> n;
    vector<int> E(h*w, -1);
    rep (i, n) {
        int r, c, e;
        cin >> r >> c >> e;

        E[(r-1)*w+c-1] = e;
    }

    if (E[si] == -1) {
        cout << "No" << '\n';
        return 0;
    }

    priority_queue<pair<int, int>> pq;
    pq.push({E[si], si});

    vector<int> me(h*w, -1);
    me[si] = E[si];
    
    while (pq.size()) {
        auto [ce, i] = pq.top();
        pq.pop();

        if (ce < me[i]) continue;
        if (ce == 0) continue;

        for (int ni : G[i]) {
            int ne = max(ce - 1, E[ni]);
            if (ne < 0) continue;
            if (me[ni] >= ne) continue;

            if (ni == ti) {
                cout << "Yes" << '\n';
                return 0;
            }

            me[ni] = ne;
            pq.push({ne, ni});
        }
    }

    cout << "No" << '\n';

    return 0;
}