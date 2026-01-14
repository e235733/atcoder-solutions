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

    int prev_a = 0;

    bool is_increasing = true;

    for (int i=0; i!=n; ++i) {
        int a;
        cin >> a;
        if (prev_a >= a) {
            is_increasing = false;
            break;
        }
        prev_a = a;
    }

    if (is_increasing) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    return 0;
}