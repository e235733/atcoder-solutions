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

    if (k == 1) {
        cout << n - 1 << '\n';
        return 0;
    }

    vector<int> count(n+1, 0);
    int result = 0;
    for (int i=2; i!=n+1; ++i) {
        if (count[i] != 0) {
            if (count[i] >= k) {
                result++;
            }
            continue;
        }

        for (int j=i; j<n+1; j+=i) {
            count[j]++;
        }
    }
    //debug(count);
    
    cout << result << '\n';

    return 0;
}