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

    int n_c = 0;
    int count = 0;
    for (char c : s) {
        if (c == 'O') {
            n_c++;
        }
        else {
            count += n_c / k;
            n_c = 0;
        }
    }
    count += n_c / k;

    cout << count << '\n';

    return 0;
}