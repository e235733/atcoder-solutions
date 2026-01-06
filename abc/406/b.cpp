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

    int n, k;
    cin >> n >> k;

    ll prev_v = 1;
    ll max_v = 1; 
    rep(i, k) {
        max_v *= 10;
    }

    rep(i, n) {
        ll current_v;
        cin >> current_v;
        // prev_v * current_v >= max_v
        if (prev_v > (max_v-1) / current_v) {
            prev_v = 1;
        }
        else {
            prev_v *= current_v;
        }
    }

    cout << prev_v << endl;

    return 0;
}