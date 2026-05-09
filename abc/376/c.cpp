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
    vector<int> B(n-1);
    rep (i, n) {
        cin >> A[i];
    }
    rep (i, n-1) {
        cin >> B[i];
    }

    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());

    int x = -1;
    int i = 0;
    int j = 0;
    while (j != n-1) {
        if (B[j] >= A[i]) {
            i++;
            j++;
        }
        else {
            if (x != -1) {
                cout << -1 << '\n';
                return 0;
            }
            x = A[i];
            i++;
        }
    }
    if (x == -1) {
        cout << A[n-1] << '\n';
    }
    else {
        cout << x << '\n';
    }

    return 0;
}