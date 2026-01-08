#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    ll n, m;
    cin >> n >> m;

    bool is_overflowed = false;
    ll result = 0;
    rep(i, m+1) {
        result += 1LL * pow(n, i);
        if (result > 1000000000) {
            is_overflowed = true;
            break;
        }
    }

    if (is_overflowed) {
        cout << "inf" << endl;
    }
    else {
        cout << result << endl;
    }

    return 0;
}