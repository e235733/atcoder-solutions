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

    int n, m;
    cin >> n >> m;

    vector<int> A(n), B(m);
    rep (i, n) {
        cin >> A[i];
    }
    rep (i, m) {
        cin >> B[i];
    }
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());

    int j = 0;
    int count = 0;
    rep (i, n) {
        while (true) {
            if (j == m) {
                break;
            }
            if (A[i] * 2 >= B[j]) {
                count++;
                break;
            }
            j++;
        }
        if (j == m) {
            break;
        }
        j++;
    }

    cout << count << '\n';

    return 0;
}