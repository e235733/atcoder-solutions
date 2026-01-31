#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

bool is_palindrome(ll v, int first_a) {
    string s = "";
    ll prev_a = 1;
    ll current_a = first_a;
    while (v != 0) {
        int s_i = v % current_a / prev_a;
        v -= 1LL * s_i * current_a / first_a;
        s += s_i + '0';
        prev_a = current_a;
        current_a *= first_a;
    }
    string r_s = s;
    reverse(s.begin(), s.end());
    debug(r_s);
    if (s == r_s) {
        debug("this is palindrome");
        return true;
    }
    else {
        return false;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    int a;
    ll n;
    cin >> a >> n;
    debug(a, n);

    ll result = 0;

    ll v = 0;
    int i = 0;
    while(true) {
        int half_min = pow(10, i);
        for(int j=half_min; j!=half_min*10; ++j) {
            v = 1LL * j * pow(10, i);
            rep(k, i) {
                int l = pow(10, k+1);
                int m = pow(10, i-k-1);
                v += j/l%10*m;
            }
            debug(v);
            if (v > n) {
                cout << result << endl;
                return 0;
            }
            if (is_palindrome(v, a)) {
                result += v;
            }
        }
        for(int j=half_min; j!=half_min*10; ++j) {
            v = 1LL * j * pow(10, i+1);
            rep(k, i+1) {
                int l = pow(10, k);
                int m = pow(10, i-k);
                v += j/l%10*m;
            }
            debug(v);
            if (v > n) {
                cout << result << endl;
                return 0;
            }
            if (is_palindrome(v, a)) {
                result += v;
            }
        }
        i++;
    }

    return 0;
}