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

    int n, a;
    cin >> n >> a;

    rep (i, n) {

        char op;
        int b;
        cin >> op >> b;

        bool is_error = false;
        switch (op) {
            case '+':
                a += b;
                cout << i + 1 << ':' << a << endl;
                break;
            case '-':
                a -= b;
                cout << i + 1 << ':' << a << endl;
                break;
            case '*':
                a *= b;
                cout << i + 1 << ':' << a << endl;
                break;
            case '/':
                if (b == 0) {
                    is_error = true;
                    cout << "error" << endl;
                }
                else {
                    a /= b;
                    cout << i + 1 << ':' << a << endl;
                }
                break;
        }
        if (is_error) {
            break;
        }
    }

    return 0;
}