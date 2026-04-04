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
    
    vector<int> A(n), B(n);
    rep (i, n) {
        cin >> A[i] >> B[i];
    }

    int m;
    cin >> m;
    vector<string> S(m);
    // 文字列の長さ、任意の位置に任意の文字が存在するか
    vector<vector<vector<bool>>> check(11, vector<vector<bool>>(11, vector<bool>(256, false)));
    rep (i, m) {
        string s;
        cin >> s;

        int length = s.size();
        rep (j, length) {
            check[length][j+1][s[j]] = true;
        }

        S[i] = s;
    }

    rep (i, m) {
        string s = S[i];
        int length = s.size();
        if (length != n) {
            cout << "No" << '\n';
            continue;
        }
        
        bool is_ok = true;
        rep (j, n) {
            if (!check[A[j]][B[j]][s[j]]) {
                is_ok = false;
                break;
            }
        }
        if (is_ok) {
            cout << "Yes" << '\n';
        }
        else {
            cout << "No" << '\n';
        }
    }

    return 0;
}