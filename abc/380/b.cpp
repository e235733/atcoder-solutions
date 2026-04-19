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
    cin >> s;
    int length = s.size();

    int count = 0;
    for (int i=1; i!=length; ++i) {
        if (s[i] == '-') {
            count++;
        }
        else {
            cout << count << ' ';
            count = 0;
        }
    }
    cout << '\n';

    return 0;
}