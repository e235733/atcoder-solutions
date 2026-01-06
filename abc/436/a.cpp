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
    string s;

    cin >> n >> s;

    int length = s.size();

    rep(i, n-length) {
        cout << 'o';
    }

    cout << s << endl;

    return 0;
}