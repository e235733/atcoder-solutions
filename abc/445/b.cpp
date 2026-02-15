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

    int max_length = 0;
    vector<string> s(n);
    rep (i, n) {
        cin >> s[i];
        int length = s[i].size();
        max_length = max(max_length, length);
    }
    
    rep (i, n) {
        int length = s[i].size();
        int k = (max_length - length) / 2;
        string result = "";
        rep (j, k) {
            result += '.';
        }
        result += s[i];
        rep (j, k) {
            result += '.';
        }

        cout << result << endl;
    }

    return 0;
}