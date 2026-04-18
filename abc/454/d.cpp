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

    int t;
    cin >> t;

    rep (_, t) {
        string a, b;
        cin >> a >> b;

        int len_a = a.size();
        int len_b = b.size();
        if ((len_a - len_b) % 2 == 1) {
            cout << "No" << '\n';
            continue;
        }

        char b2 = ')';
        char b1 = ')';
        bool is_ok = false;
        int dist;
        rep (i, len_a) {
            if (is_ok) {
                if (i - dist >= 0) {
                    if (a[i] == ')' && a[i-dist] == '(') {
                        a[i] = '.';
                        a[i-dist] = '.';
                        dist += 2;
                    }
                    else {
                        is_ok = false;
                    }
                }
                else {
                    is_ok = false;
                }
            }
            else {
                if (a[i] == ')' && b1 == 'x' && b2 == 'x') {
                    if (i - 3 >= 0) {
                        if (a[i-3] == '(') {
                            a[i] = '.';
                            a[i-3] = '.';
                            is_ok = true;
                            dist = 5;
                        }
                    }
                }
            }
            b2 = b1;
            b1 = a[i];
        }
        debug(a);

        b2 = ')';
        b1 = ')';
        is_ok = false;
        rep (i, len_b) {
            if (is_ok) {
                if (i - dist >= 0) {
                    if (b[i] == ')' && b[i-dist] == '(') {
                        b[i] = '.';
                        b[i-dist] = '.';
                        dist += 2;
                    }
                    else {
                        is_ok = false;
                    }
                }
                else {
                    is_ok = false;
                }
            }
            else {
                if (b[i] == ')' && b1 == 'x' && b2 == 'x') {
                    if (i - 3 >= 0) {
                        if (b[i-3] == '(') {
                            b[i] = '.';
                            b[i-3] = '.';
                            is_ok = true;
                            dist = 5;
                        }
                    }
                }
            }
            b2 = b1;
            b1 = b[i];
        }
        debug(b);

        string t_a = "";
        string t_b = "";
        rep (i, len_a) {
            if (a[i] != '.') {
                t_a += a[i];
            }
        }
        rep (i, len_b) {
            if (b[i] != '.') {
                t_b += b[i];
            }
        }
        debug(t_a);
        debug(t_b);

        if (t_a == t_b) {
            cout << "Yes" << '\n';
        }
        else {
            cout << "No" << '\n';
        }
    }

    return 0;
}