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
    string s, t;
    cin >> n >> s >> t;

    int hum_dist = 0;
    rep(i, n) {
        if (s.at(i) != t.at(i)) {
            hum_dist++;
        }
    }

    cout << hum_dist << endl;

    return 0;
}