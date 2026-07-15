#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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

    vector<int> V = {0, 2, 4, 6, 8};

    ll n;
    cin >> n;

    if (n == 1LL) cout << 0 << '\n';

    --n;
    vector<int> ans;
    while (n != 0) {
        ans.push_back(n % 5);
        n /= 5;
    }
    debug(ans);


    for (int i=(int)ans.size()-1; i!=-1; --i) {
        cout << V[ans[i]];
    }
    cout << '\n';

    return 0;
}