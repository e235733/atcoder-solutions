#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    int n;
    cin >> n;

    string result = "";

    if (n % 2 == 0) {
        int num_minus = n / 2 - 1;

        rep(i, num_minus) {
            result += '-';
        }
        result += "==";
        rep(i, num_minus) {
            result += '-';
        }
    }
    else {
        int num_minus = (n - 1) / 2;

        rep(i, num_minus) {
            result += '-';
        }
        result += '=';
        rep(i, num_minus) {
            result += '-';
        }
    }

    cout << result << endl;

    return 0;
}