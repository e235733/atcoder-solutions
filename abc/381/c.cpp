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
    string s;
    cin >> n >> s;

    bool is_ok = false;
    int count_one = 0;
    int count_two = 0;
    char prev = '/';
    int max_length = 1;
    rep (i, n) {
        if (s[i] == '1') {
            if (is_ok) {
                if (prev == '1') {
                    count_one++;
                }
                else if (prev == '/') {
                    count_one = 1;
                }
                else {
                    int length = min(count_one, count_two) * 2 + 1;
                    max_length = max(max_length, length);
                    is_ok = false;
                    count_one = 1;
                    count_two = 0;
                }
            }
            else {
                is_ok = true;
                count_one = 1;
            }
        }
        else if (s[i] == '/') {
            if (is_ok) {
                if (prev == '/') {
                    is_ok = false;
                    count_one = 0;
                }
                else if (prev == '2') {
                    int length = min(count_one, count_two) * 2 + 1;
                    max_length = max(max_length, length);
                    is_ok = false;
                    count_one = 0;
                }
            }
        }
        else {
            if (is_ok) {
                if (prev == '1') {
                    is_ok = false;
                    count_one = 0;
                }
                else if (prev == '/') {
                    count_two = 1;
                }
                else {
                    count_two++;
                }
            }
        }
        prev = s[i];
    }
    int length = min(count_one, count_two) * 2 + 1;
    max_length = max(max_length, length);
    cout << max_length << '\n';

    return 0;
}