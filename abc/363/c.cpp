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

    int n, k;
    string s;
    cin >> n >> k >> s;
    sort(s.begin(), s.end());
    int count = 0;
    do {
        //debug(s);
        bool ok = true;
        rep (i, n-k+1) {
            ok = true;
            rep (j, k/2) {
                if (s[i+j] != s[i+k-j-1]) {
                    ok = false;
                    break;
                }
            }
            if (ok) break;
        }
        if (!ok) count++;
    } while (next_permutation(s.begin(), s.end()));

    cout << count << '\n';

    return 0;
}