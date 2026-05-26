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
    sort(A.begin(), A.end());

    int j = n-n/2;
    int count = 0;
    rep (i, n/2) {
        while (A[i]*2 > A[j]) {
            if (j == n) {
                break;
            }
            j++;
        }
        if (j == n) {
            break;
        }
        count++;
        j++;
    }
    cout << count << '\n';

    return 0;
}