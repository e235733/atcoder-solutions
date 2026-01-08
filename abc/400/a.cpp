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

    int a;
    cin >> a;

    if (400 % a == 0) {
        cout << 400 / a << endl;
    }
    else {
        cout << -1 << endl;
    }

    return 0;
}