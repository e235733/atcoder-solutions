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

    vector<int> points(n);
    int sum = 0;
    rep (i, n) {
        int a;
        cin >> a;
        points[i] = a;
        sum += a;
    }

    int average = sum / n;
    rep (i, n) {
        int p = points[i];
        cout << abs(p - average) << endl;
    }

    return 0;
}