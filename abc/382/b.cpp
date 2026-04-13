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

    int n, d;
    string s;
    cin >> n >> d >> s;

    int count = 0;
    int idx = n - 1;
    while (count != d) {
        if (s[idx] == '@') {
            count++;
            s[idx] = '.';
        }
        idx--;
    }

    cout << s << '\n';

    return 0;
}