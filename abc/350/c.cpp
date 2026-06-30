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

    int n;
    cin >> n;
    vector<int> A(n+1), pos(n+1);
    rep (i, n) {
        int a;
        cin >> a;
        A[i+1] = a;
        pos[a] = i+1;
    }

    vector<int> p1, p2;
    rep (i, n) {
        if (A[i+1] == i+1) continue;

        p1.push_back(pos[A[i+1]]);
        p2.push_back(pos[i+1]);

        pos[A[i+1]] = pos[i+1];
        A[pos[i+1]] = A[i+1];
    }

    int len = p1.size();
    cout << len << '\n';
    
    rep (i, len) {
        cout << p1[i] << ' ' << p2[i] << '\n';
    }

    return 0;
}