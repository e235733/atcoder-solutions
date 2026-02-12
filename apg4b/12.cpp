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

    string s;
    cin >> s;
    int num_op = s.size() / 2;

    int a = 1;
    rep (i, num_op) {
        char op = s[1+i*2];
        if (op == '+') {
            a++;
        }
        else {
            a--;
        }
    }
    cout << a << endl;

    return 0;
}