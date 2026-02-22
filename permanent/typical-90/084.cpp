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

    ll count = 0;

    // 尺取り法で2つの文字を含む区間を探す
    int l = 0;
    int r = 1;
    char another;
    if (s[l] == 'o') {
        another = 'x';
    }
    else {
        another = 'o';
    }

    while (r != n) {
        if (s[r] == another) {
            count += n - r;
            if (l + 1 == r) {
                l++;
                r++;
            }
            else {
                l++;
            }
            if (s[l] == 'o') {
                another = 'x';
            }
            else {
                another = 'o';
            }
        }
        else {
            r++;
        }
    }
    
    cout << count << '\n';

    return 0;
}