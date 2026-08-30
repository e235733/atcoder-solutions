#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

void dfs(vector<int> vec, int m, int n, int k, int s) {
    if (m == n - 1) {
        for (int a=0; s+m*a<=k; ++a) {
            if ((k-s-m*a)%n!=0) continue;
            vec[m-1] = a;
            vec[n-1] = (k - s - m * a) / n;

            rep (i, n) {
                cout << vec[i] << ' ';
            }
            cout << '\n';
        }
    }
    else {
        for (int a=0; s+m*a<=k; ++a) {
            vec[m-1] = a;
            dfs(vec, m+1, n, k, s+m*a);
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    int n, k;
    cin >> n >> k;

    if (n == 1) {
        cout << k << '\n';
        return 0;
    }

    vector<int> vec(n);
    dfs(vec, 1, n, k, 0);

    return 0;
}