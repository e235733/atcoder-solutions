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

    vector<int> P(n+1);
    rep (i, n) {
        cin >> P[i+1];
    }

    vector<bool> is_used(n+1, false);
    // サイクルを探し、組み合わせの個数を数える
    ll count = 0;
    for (int i=1; i!=n+1; ++i) {
        if (is_used[i]) {
            continue;
        }
        is_used[i] = true;
        if (P[i] == i) {
            continue;
        }
        int j = P[i];
        is_used[j] = true;
        // サイズはノードの数
        int size = 2;
        while (P[j] != i) {
            j = P[j];
            size++;
            is_used[j] = true;
        }
        debug(i, size);

        count += 1LL * size * (size - 1) / 2;
    }

    cout << count << '\n';

    return 0;
}