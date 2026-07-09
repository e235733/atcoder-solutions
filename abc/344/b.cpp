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

    vector<int> A;
    while (true) {
        int a;
        cin >> a;
        A.push_back(a);

        if (a == 0) break;
    }

    reverse(A.begin(), A.end());
    for (int a : A) {
        cout << a << '\n';
    }

    return 0;
}