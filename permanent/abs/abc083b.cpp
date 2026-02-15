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

    int n, a, b;
    cin >> n >> a >> b;

    int result = 0;
    rep (i, n+1) {
        int sum = 0;
        int number = i;
        debug(number);
        while (number != 0) {
            sum += number % 10;
            number /= 10;
        }
        debug(sum);
        if (sum >= a && sum <= b) {
            result += i;
        }
    }

    cout << result << endl;

    return 0;
}