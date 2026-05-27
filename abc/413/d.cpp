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

    int t;
    cin >> t;

    rep (_, t) {
        int n;
        cin >> n;

        vector<ll> A(n);
        rep (i, n) {
            cin >> A[i];
        }

        if (n == 2) {
            cout << "Yes" << '\n';
            continue;
        }

        sort(A.begin(), A.end(), [](ll a, ll b) {
            return abs(a) < abs(b);
        });
        debug(A);

        if (abs(A.front()) == abs(A.back())) {
            int cm = 0;
            int cp = 0;

            rep (i, n) {
                if (A[i] < 0) {
                    cm++;
                }
                else if (A[i] > 0) {
                    cp++;
                }
            }

            if (abs(cm - cp) <= 1 || cm == n || cp == n) {
                cout << "Yes" << '\n';
            }
            else {
                cout << "No" << '\n';
            }
            continue;
        }

        bool ok = true;
        rep (i, n-2) {
            if (A[i] * A[i+2] != A[i+1] * A[i+1]) {
                ok = false;
                break;
            }
        }

        if (ok) {
            cout << "Yes" << '\n';
        }
        else {
            cout << "No" << '\n';
        }
    }

    return 0;
}