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

    int h, w, n;
    cin >> h >> w >> n;

    vector<vector<int>> A(h, vector<int>(w));
    rep(i, h) {
        rep(j, w) {
            int a;
            cin >> a;
            A.at(i).at(j) = a;
        }
    }

    vector<int> count(h, 0);
    rep(i, n) {
        int b;
        cin >> b;
        rep(i, h) {
            rep(j, w) {
                if (A.at(i).at(j) == b) {
                    count.at(i) += 1;
                }
            }
        }
    }
    int max_value = 0;
    rep(i, h) {
        if (count.at(i) > max_value) {
            max_value = count.at(i);
        }
    }
    cout << max_value << endl;

    return 0;
}