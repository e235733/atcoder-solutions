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
    string t;
    string a;
    cin >> n >> t >> a;

    bool is_conflicted = false;

    rep(i, n) {
        if (t.at(i) == 'o' && a.at(i) == 'o') {
            is_conflicted = true;
            break;
        }
    }

    if (is_conflicted) {
        cout << "Yes" << endl;
    } 
    else {
        cout << "No" << endl;
    }

    return 0;
}