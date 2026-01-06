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

    vector<vector<int>> m(n, vector<int>(n, 0));

    m.at(0).at((n-1)/2) = 1;
    pair<int, int> prev_p(0, (n-1)/2);
    int prev_v = 1;

    rep(i, n*n-1) {
        int next_v = prev_v + 1;

        if (m.at((prev_p.first - 1 + n) % n).at((prev_p.second + 1) % n) == 0) {
            m.at((prev_p.first - 1 + n) % n).at((prev_p.second + 1) % n) = next_v;
            prev_p.first = (prev_p.first - 1 + n) % n;
            prev_p.second = (prev_p.second + 1) % n;
            //cout << "blank " << next_v << endl;
        }
        else {
            m.at((prev_p.first + 1) % n).at(prev_p.second) = next_v;
            prev_p.first = (prev_p.first + 1) % n;
            //cout << "filled " << next_v << endl;
        }
        prev_v = next_v;
    }

    rep(i, n) {
        rep(j, n) {
            cout << m.at(i).at(j) << ' ';
        }
        cout << endl;
    }

    return 0;
}