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
    cin >> n >> k;
    // 部分点から満点、0点から部分点にする際の点数の上昇
    vector<int> gain(n*2);
    rep (i, n) {
        int a, b;
        cin >> a >> b;
        gain[i*2] = a - b;
        gain[i*2+1] = b;
    }
    debug(gain);

    // 降順にソートし、先頭 k 個を選ぶのが最大値
    sort(gain.rbegin(), gain.rend());
    ll result = 0;
    rep (i, k) {
        result += gain[i];
    }
    
    cout << result << '\n';

    return 0;
}