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

    vector<int> wall(n, 0);

    rep(i, m) {
        int l, r;
        cin >> l >> r;
        wall.at(l-1) += 1;
        if (r != n) {
            wall.at(r) -= 1;
        }
    }
    //rep(i, n) {cout << wall.at(i) << ' ';} cout << endl;

    int num_protection = 0;
    rep(i, n) {
        num_protection += wall.at(i);
        wall.at(i) = num_protection;
    }
    //rep(i, n) {cout << wall.at(i) << ' ';} cout << endl;

    cout << *min_element(wall.begin(), wall.end()) << endl;

    return 0;
}