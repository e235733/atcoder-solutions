#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

int n, m, k;

vector A(100, vector<bool>(15));
vector<bool> R(100);

vector<vector<bool>> P;
void pick(int c, vector<bool> &p) {
    if (c == n) {
        P.push_back(p);
        return ;
    }

    p.push_back(true);
    pick(c+1, p);
    p.pop_back();
    p.push_back(false);
    pick(c+1, p);
    p.pop_back();
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    cin >> n >> m >> k;

    rep (i, m) {
        int c;
        cin >> c;
        rep (j, c) {
            int a;
            cin >> a;
            a--;
            A[i][a] = true;
        }

        char r;
        cin >> r;
        if (r == 'o') R[i] = true;
        else R[i] = false;
    }
    debug(A);

    vector<bool> p;
    pick(0, p);
    debug(P);

    int len = P.size();
    int ans = 0;
    rep (i, len) {
        debug(P[i]);
        vector<int> count(m, 0);
        rep (j, m) {
            debug(A[j]);
            rep (k, n) {
                if (P[i][k] && A[j][k]) count[j]++;
            }
        }
        debug(count);
        bool ok = true;
        rep (j, m) {
            if (R[j] && count[j] < k) {
                ok = false;
                break;
            }
            else if (!R[j] && count[j] >= k) {
                ok = false;
                break;
            }
        }
        debug(ok);
        if (ok) ans++;
    }

    cout << ans << '\n';

    return 0;
}