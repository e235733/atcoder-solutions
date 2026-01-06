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

    int n, m;
    cin >> n >> m;
    set<int> s;

    int filled = 0;

    rep(i, n) {
        int a;
        cin >> a;
        if (a <= m) {
            s.insert(a);
            if (s.size() == m) {
                filled = n-i;
                break;
            }
        }
    }

    cout << filled << endl;

    return 0;
}