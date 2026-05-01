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

    int size = 2000;

    int n;
    cin >> n;
    vector<vector<int>> m(n, vector<int>(4));
    rep (i, n) {
        rep (j, 4) {
            cin >> m[i][j];
        }
    }

    vector<vector<int>> imos(size+1, vector<int>(size+1, 0));
    rep (i, n) {
        int u = m[i][0] - 1;
        int d = m[i][1];
        int l = m[i][2] - 1;
        int r = m[i][3];

        imos[u][l] += 1;
        imos[u][r] += -1;
        imos[d][l] += -1;
        imos[d][r] += 1;
    }
    //debug(imos);
    rep (i, size+1) {
        rep (j, size) {
            imos[i][j+1] += imos[i][j];
        }
    }
    //debug(imos);
    rep (i, size) {
        rep (j, size+1) {
            imos[i+1][j] += imos[i][j];
        }
    }
    debug(imos);

    vector<vector<int>> count(size+1, vector<int>(size+1, 0));
    int cloud = 0;
    rep (i, size) {
        rep (j, size) {
            count[i+1][j+1] = count[i][j+1] + count[i+1][j] - count[i][j];
            if (imos[i][j] != 0) {
                cloud++;
                if (imos[i][j] == 1) {
                    count[i+1][j+1]++;
                }
            }
        }
    }
    debug(count);
    debug(cloud);

    int all = 2000 * 2000;
    rep (i, n) {
        int u = m[i][0] - 1;
        int d = m[i][1];
        int l = m[i][2] - 1;
        int r = m[i][3];
        int num_one = count[d][r] - count[u][r] - count[d][l] + count[u][l];
        debug(num_one);

        cout << all - cloud + num_one << '\n';
    }

    return 0;
}