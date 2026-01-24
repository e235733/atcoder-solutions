#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    string s;
    cin >> s;

    // i, j なら加算する
    int count = 0;
    rep (i, (int)s.size()) {
        if (s.at(i) == 'i' || s.at(i) == 'j') {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}