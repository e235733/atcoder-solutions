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

    int n, s;
    cin >> n >> s;
    
    vector<int> a(n), p(n);
    rep (i, n) {
        int a_i;
        cin >> a_i;
        a[i] = a_i;
    }
    rep (i, n) {
        int p_i;
        cin >> p_i;
        p[i] = p_i;
    }

    int count = 0;
    rep (i, n) {
        int a_p = a[i];
        rep (j, n) {
            int p_p = p[j];
            if (a_p + p_p == s) {
                count++;
            }
        }
    }
    cout << count << endl;

    return 0;
}