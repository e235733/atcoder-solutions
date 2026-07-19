#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    int n, q;
    cin >> n >> q;

    vector<int> X(n), Y(n, 0);
    rep (i, n) {
        X[i] = n - i;
    }
    debug(X);
    debug(Y);
    
    int m = 0;
    rep (_, q) {
        debug(m);
        int t;
        cin >> t;
        if (t == 1) {
            char c;
            cin >> c;
            debug(c);
            switch (c) {
                case 'R': 
                X.push_back(X.back()+dx[0]);
                Y.push_back(Y.back()+dy[0]);
                break;

                case 'L': 
                X.push_back(X.back()+dx[1]);
                Y.push_back(Y.back()+dy[1]);
                break;

                case 'U': 
                X.push_back(X.back()+dx[2]);
                Y.push_back(Y.back()+dy[2]);
                break;

                case 'D': 
                X.push_back(X.back()+dx[3]);
                Y.push_back(Y.back()+dy[3]);
                break;
            }
            ++m;
            debug(X);
            debug(Y);
        }
        else if (t == 2) {
            int p;
            cin >> p;
            debug(p);

            cout << X[n+m-p] << ' ' << Y[n+m-p] << '\n';
        }
    }

    return 0;
}