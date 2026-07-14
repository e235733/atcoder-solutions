#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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

    int n;
    cin >> n;
    vector<int> pp(n*2+1);
    rep (i, n) {
        int a, b;
        cin >> a >> b;
        pp[a] = b;
        pp[b] = a;
    }

    stack<int> S;
    for (int i=1; i!=n*2+1; ++i) {
        if (pp[pp[i]] != -1) {
            S.push(i);
            pp[i] = -1;
        }
        else {
            if (S.top() != pp[i]) {
                cout << "Yes" << '\n';
                return 0;
            }

            S.pop();
        }
    }

    cout << "No" << '\n';

    return 0;
}