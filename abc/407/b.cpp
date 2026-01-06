#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    int x, y;
    cin >> x >> y;

    int count = 0;

    for (int i=1; i<=6; i++) {
        for (int j=1; j<=6; j++) {
            if (i + j >= x || abs(i - j) >= y) {
                count++;
            }
        }
    }

    double result = double(count) / 36;

    cout << fixed << setprecision(10) << result << endl;

    return 0;
}