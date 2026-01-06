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

    ll sum_a = 0;
    vector<int> A(n);
    rep(i, n) {
        int a;
        cin >> a;
        sum_a += a;
        A.at(i) = a;
    }

    ll result_double = 0;
    rep(i, n) {
        result_double += A.at(i) * (sum_a - A.at(i));
    }

    cout << result_double / 2 << endl;

    return 0;
}