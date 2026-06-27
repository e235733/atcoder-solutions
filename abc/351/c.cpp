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

    vector<int> B;
    rep (i, n) {
        int a;
        cin >> a;
        B.push_back(a);

        while (B.size() > 1) {
            int e = B.size() - 1;
            if (B[e] != B[e-1]) break;

            B.pop_back();
            B[e-1]++;
        }
    }

    cout << B.size() << '\n';

    return 0;
}