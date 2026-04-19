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

    string s;
    int q;
    cin >> s >> q;

    ll length = s.size();
    rep (i, q) {
        ll k;
        cin >> k;
        k--; 

        ll num_loop = k / length; 
        ll idx = k % length;
        ll temp_loop = num_loop;
        
        bool is_flipped = false; 
        while(temp_loop != 0) {
            if (temp_loop % 2 == 1) {
                is_flipped = !is_flipped;
            }
            temp_loop /= 2;
        }

        if (i > 0) cout << " ";

        if (is_flipped) {
            char result;
            if ('a' <= s[idx] && s[idx] <= 'z') {
                result = s[idx] - 'a' + 'A';
            } else {
                result = s[idx] - 'A' + 'a';
            }
            cout << result;
        } else {
            cout << s[idx];
        }
    }
    cout << '\n';

    return 0;
}