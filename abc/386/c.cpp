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

    int k;
    string s, t;
    cin >> k >> s >> t;

    if (s == t) {
        cout << "Yes" << '\n';
        return 0;
    }

    int len_s = s.size();
    int len_t = t.size();

    if (len_s == len_t - 1) {
        int count_lack = 0;
        int i = 0;
        for (int j=0; j!=len_t; ++j) {
            if (s[i] == t[j]) {
                i++;
                if (i == len_s) {
                    break;
                }
            }
            else {
                count_lack++;
                if (count_lack == 2) {
                    break;
                }
            }
        }
        if (count_lack == 2) {
            cout << "No" << '\n';
        }
        else {
            cout << "Yes" << '\n';
        }
    }
    else if (len_s == len_t) {
        int count_diff = 0;
        rep (i, len_s) {
            if (s[i] != t[i]) {
                count_diff++;
                if (count_diff == 2) {
                    break;
                }
            }
        }
        if (count_diff == 2) {
            cout << "No" << '\n';
        }
        else {
            cout << "Yes" << '\n';
        }
    }
    else if (len_s - 1 == len_t) {
        int count_lack = 0;
        int j = 0;
        for (int i=0; i!=len_t; ++i) {
            if (s[i] == t[j]) {
                j++;
                if (j == len_t) {
                    break;
                }
            }
            else {
                count_lack++;
                if (count_lack == 2) {
                    break;
                }
            }
        }
        if (count_lack == 2) {
            cout << "No" << '\n';
        }
        else {
            cout << "Yes" << '\n';
        }
    }
    else {
        cout << "No" << '\n';
    }

    return 0;
}