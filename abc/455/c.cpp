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
    unordered_map<ll, int> A;
    rep (_, n) {
        ll a;
        cin >> a;
        A[a]++;
    }
    debug(A);

    int length = A.size();

    if (k >= length) {
        cout << 0 << '\n';
        return 0;
    }

    vector<ll> sum;
    sum.reserve(length);
    for (auto p : A) {
        sum.push_back(p.first * p.second);
    }
    sort(sum.rbegin(), sum.rend());
    debug(sum);

    ll result = 0;
    for (int i=k; i!=length; ++i) {
        result += sum[i];
    }
    cout << result << '\n';

    return 0;
}