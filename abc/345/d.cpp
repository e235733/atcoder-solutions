#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

void dfs (vector<int> &area, int i, int n, int aim, int ca, vector<int> C, vector<vector<int>> &Q) {
    if (ca == aim) {
        Q.push_back(C);
        return;
    }

    if (ca > aim || i == n) return;

    dfs (area, i+1, n, aim, ca, C, Q);
    C.push_back(i);
    dfs (area, i+1, n, aim, ca+area[i], C, Q);
}

bool solve(vector<vector<char>> &S, vector<pair<int, int>> &P, int i, int n, vector<int> &A, vector<int> &B, int h, int w) {
    /*
    rep (i, h) {
        rep (j, w) {
            cout << S[i][j];
        }
        cout << '\n';
    }
    debug(i);
    */

    if (i == n) return true;
    rep (sr, h) rep (sc, w) {
        int er1 = sr + A[P[i].second];
        int ec1 = sc + B[P[i].second];

        if (er1 > h || ec1 > w) continue;
        debug(sr, er1, sc, ec1);

        bool empty1 = true;
        for (int r=sr; r!=er1; ++r) for (int c=sc; c!=ec1; ++c) {
            if (S[r][c] == '#') {
                empty1 = false;
                break;
            }
        }
        if (!empty1) continue;

        for (int r=sr; r!=er1; ++r) for (int c=sc; c!=ec1; ++c) {
            S[r][c] = '#';
        }
        bool ok1 = solve(S, P, i+1, n, A, B, h, w);
        for (int r=sr; r!=er1; ++r) for (int c=sc; c!=ec1; ++c) {
            S[r][c] = '.';
        }
        if (ok1) return true;
    }

    rep (sr, h) rep (sc, w) {
        int er2 = sr + B[P[i].second];
        int ec2 = sc + A[P[i].second];

        if (er2 > h || ec2 > w) continue;
        debug(sr, er2, sc, ec2);

        bool empty2 = true;
        for (int r=sr; r!=er2; ++r) for (int c=sc; c!=ec2; ++c) {
            if (S[r][c] == '#') {
                empty2 = false;
                break;
            }
        }
        if (!empty2) continue;

        for (int r=sr; r!=er2; ++r) for (int c=sc; c!=ec2; ++c) {
            S[r][c] = '#';
        }
        bool ok2 = solve(S, P, i+1, n, A, B, h, w);
        for (int r=sr; r!=er2; ++r) for (int c=sc; c!=ec2; ++c) {
            S[r][c] = '.';
        }
        if (ok2) return true;
    }

    return false;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    int n, h, w;
    cin >> n >> h >> w;

    vector<int> A(n), B(n);
    rep (i, n) cin >> A[i] >> B[i];

    vector<int> area(n);
    rep (i, n) {
        area[i] = A[i] * B[i];
    }
    debug(area);

    vector<vector<int>> Q;
    dfs (area, 0, n, h*w, 0, {}, Q);
    debug(Q);

    vector S(h, vector<char>(w, '.'));

    for (vector<int> q : Q) {
        int len = q.size();
        vector<pair<int, int>> P(len);
        rep (i, len) {
            P[i] = {area[q[i]], q[i]};
        }
        sort(P.rbegin(), P.rend());
        debug(P);

        if (solve(S, P, 0, len, A, B, h, w)) {
            cout << "Yes" << '\n';
            return 0;
        }
    }

    cout << "No" << '\n';

    return 0;
}