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
    string s;

    cin >> n >> s;

    int i = 0;
    while (s[i] == 'o') {
        i++;
    }

    for (int j=i; j!=n; ++j) {
        cout << s[j];
    }
    cout << '\n';

    return 0;
}