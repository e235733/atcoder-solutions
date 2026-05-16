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

    int x, q;
    cin >> x >> q;

    priority_queue<int> smaller;
    priority_queue<int, vector<int>, greater<int>> bigger;

    rep (_, q) {
        int a, b;
        cin >> a >> b;
        debug(a, b);
        if (a < x && b < x) {
            bigger.push(x);
            smaller.push(a);
            smaller.push(b);
            x = smaller.top();
            smaller.pop();
        }
        else if (a > x && b > x) {
            smaller.push(x);
            bigger.push(a);
            bigger.push(b);
            x = bigger.top();
            bigger.pop();
        }
        else {
            smaller.push(min(a, b));
            bigger.push(max(a, b));
        }
        cout << x << '\n';
    }

    return 0;
}