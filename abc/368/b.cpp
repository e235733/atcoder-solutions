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

    int count = 0;
    while (true) {
        int cp = 0;
        rep (i, n) {
            if (A[i] > 0) {
                cp++;
            }
        }
        if (cp <= 1) {
            cout << count << '\n';
            return 0;
        }

        count++;
        sort(A.rbegin(), A.rend());
        A[0]--;
        A[1]--;
    }

    return 0;
}