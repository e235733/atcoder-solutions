#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

int INF = 1 << 30;

vector<int> dr = {-1, 1, 0, 0};
vector<int> dc = {0, 0, -1, 1};

struct area {
    int a, r, c;
};

void dfs (vector<vector<int>> &sink, int r, int c, int &count, int s, int h, int w) {
    count--;
    debug(r, c);
    rep (i, 4) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr == -1 || nr == h || nc == -1 || nc == w) continue;

        if (sink[nr][nc] <= s) {
            sink[nr][nc] = INF;
            dfs(sink, nr, nc, count, s, h, w);
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    int h, w, y;
    cin >> h >> w >> y;
    vector<area> A;
    A.reserve(h*w);
    vector sink(h, vector<int>(w));
    rep (i, h) {
        rep (j, w) {
            int a;
            cin >> a;
            A.push_back({a, i, j});
            sink[i][j] = a;
        }
    }
    
    sort(A.begin(), A.end(), [](area &a, area &b){
        return a.a < b.a;
    });

    int count = h * w;
    int i = 0;
    for (int s=1; s!=y+1; ++s) {
        debug(s);
        while (i != h*w) {
            debug(A[i].a, A[i].r, A[i].c);
            if (A[i].a != s) break;

            int cr = A[i].r;
            int cc = A[i].c;
            if (sink[cr][cc] != INF) {
                if (cr == 0 || cr == h-1 || cc == 0 || cc == w-1) {
                    debug("lim");
                    sink[cr][cc] = INF;
                    dfs(sink, cr, cc, count, s, h, w);
                }
                else if (sink[cr-1][cc] == INF || sink[cr+1][cc] == INF || sink[cr][cc-1] == INF || sink[cr][cc+1] == INF) {
                    debug("heart");
                    sink[cr][cc] = INF;
                    dfs(sink, cr, cc, count, s, h, w);
                }
            }
            ++i;
        }
        cout << count << '\n';
    }

    return 0;
}