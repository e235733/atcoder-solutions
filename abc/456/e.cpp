#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

bool dfs (auto& g, vector<vector<bool>>& all_used, vector<vector<bool>>& c_used, pair<int, int> current) {
    bool ok = false;
    for (auto p : g[current.first][current.second]) {
        if (c_used[p.first][p.second]) {
            return true;
        }
        if (all_used[p.first][p.second]) {
            continue; 
        }
        
        c_used[p.first][p.second] = true;
        all_used[p.first][p.second] = true;
        ok = dfs (g, all_used, c_used, p);
        if (ok) {
            return true;
        }
        c_used[p.first][p.second] = false;
    }
    return ok;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    int t;
    cin >> t;

    rep (_, t) {
        int n, m;
        cin >> n >> m;

        vector<int> U(m), V(m);
        rep (i, m) {
            cin >> U[i] >> V[i];
        }

        int w;
        cin >> w;
        vector<string> S(n);
        rep (i, n) {
            cin >> S[i];
        }

        vector<vector<vector<pair<int, int>>>> g(n+1, vector<vector<pair<int, int>>>(w));
        rep (i, n) {
            rep (j, w-1) {
                if (S[i][j] == 'o' && S[i][j+1] == 'o') {
                    g[i+1][j].push_back({i+1, j+1});
                }
            }
            if (S[i][w-1] == 'o' && S[i][0] == 'o') {
                g[i+1][w-1].push_back({i+1, 0});
            }
        }
        rep (i, m) {
            int u = U[i];
            int v = V[i];

            rep (j, w-1) {
                if (S[u-1][j] == 'o' && S[v-1][j+1] == 'o') {
                    g[u][j].push_back({v, j+1}); 
                }
                if (S[v-1][j] == 'o' && S[u-1][j+1] == 'o') {
                    g[v][j].push_back({u, j+1}); 
                }
            }
            if (S[u-1][w-1] == 'o' && S[v-1][0] == 'o') {
                g[u][w-1].push_back({v, 0}); 
            }
            if (S[v-1][w-1] == 'o' && S[u-1][0] == 'o') {
                g[v][w-1].push_back({u, 0}); 
            }
        }

        vector<vector<bool>> all_used(n+1, vector<bool>(w, false));
        vector<vector<bool>> c_used(n+1, vector<bool>(w, false));
        bool ok = false;
        
        rep (i, n) {
            if (S[i][0] == 'x') {
                continue;
            }

            if (all_used[i+1][0]) {
                continue;
            }

            all_used[i+1][0] = true;
            c_used[i+1][0] = true;

            ok = dfs(g, all_used, c_used, {i+1, 0});
            
            c_used[i+1][0] = false; 

            if (ok) {
                break;
            }
        }

        if (ok) {
            cout << "Yes" << '\n';
        }
        else {
            cout << "No" << '\n';
        }
    }

    return 0;
}