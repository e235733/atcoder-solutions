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

    string n;
    cin >> n;

    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    rep (i, 6) {
        if (n[i] == '1') {
            count1++;
        }
        else if (n[i] == '2') {
            count2++;
        }
        else if (n[i] == '3') {
            count3++;
        }
    }

    if (count1 == 1 && count2 == 2 && count3 == 3) {
        cout << "Yes" << '\n';
    }
    else {
        cout << "No" << '\n';
    }

    return 0;
}