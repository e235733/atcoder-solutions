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

    int min_count = 1000000000;
    rep (_, n) {
        int a;
        cin >> a;
        int count = 0;
        while (a % 2 == 0) {
            a /= 2;
            count++;
        }
        if (count < min_count) {
            min_count = count;
        }
    }
    cout << min_count << endl;

    return 0;
}