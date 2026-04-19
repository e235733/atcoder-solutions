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

    int n, k;
    string s;
    cin >> n >> k >> s;

    char prev = '0';
    int g_i = 0;
    int p_end, start; 
    int end = -1;
    rep (i, n) {
        if (s[i] == '0') {
            if (prev == '1') {
                if (g_i == k - 1) {
                    p_end = i;
                }
                else if (g_i == k) {
                    end = i;
                    break;
                }
            }
        }
        else {
            if (prev == '0') {
                g_i++;
                if (g_i == k) {
                    start = i;
                }
            }
        }
        prev = s[i];
    }
    if (end == -1) {
        end = n;
    }
    debug(p_end, start, end);

    for (int i=start; i!=end; ++i) {
        s[i] = '0';
    }
    for (int i=p_end; i!=p_end+end-start; ++i) {
        s[i] = '1';
    }
    cout << s << '\n';

    return 0;
}