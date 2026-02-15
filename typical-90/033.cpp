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

    int h, w;
    cin >> h >> w;

    // 高さか幅が 1 のときに対応
    if (h == 1 || w == 1) {
        cout << h * w << endl;
    }
    else {
        int num_max_h = (h + 1) / 2;
        int num_max_w = (w + 1) / 2;
        cout << num_max_h * num_max_w << endl;
    }

    return 0;
}