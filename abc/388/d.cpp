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

    int n;
    cin >> n;
    vector<int> A(n);
    rep (i, n) {
        cin >> A[i];
    }

    unordered_map<int, int> M;
    M[A[0]] = 1;
    int zero = 0;
    vector<int> result(n);
    result[0] = A[0];
    for (int i=1; i!=n; ++i) {
        debug(i, zero);
        int a = A[i];
        debug(a);

        if (M.contains(zero)) {
            int stone = a+i+1-M[zero]+zero;
            M[stone]++;
            result[i] = stone;
            int nz = M[zero];
            M.erase(zero);
            zero++;
            M[zero] += nz;
        }
        else {
            int stone = a+i+1+zero;
            M[stone]++;
            result[i] = stone;
            zero++;
        }
        debug(M);
        debug(result);
    }


    rep (i, n) {
        cout << max(result[i]-zero, 0) << ' ';
    }
    cout << '\n';

    return 0;
}