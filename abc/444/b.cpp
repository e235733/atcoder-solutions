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
    cin >> n >> k;

    int count = 0;
    rep(i, n) {
        int number = i + 1;
        int sum = 0;
        while (number != 0) {
            sum += number % 10;
            number /= 10;
        }
        if (sum == k) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}