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
    set<int> s;

    rep(i, n) {
        int a;
        cin >> a;
        s.insert(a);
    }

    cout << s.size() << endl;

    for(int c : s) {
        cout << c << ' ';
    }
    cout << endl;

    return 0;
}