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

    // 最初は全て '.' にする
    vector<vector<char>> target(n, vector<char>(n, '.'));

    rep (i, n) {
        int j = n - i;
        if (i >= j) {
            break;
        }
        else {
            // 偶数のときのみ
            if (i % 2 == 0) {
                // 矩形領域を # で埋める
                for (int k=i; k!=j; ++k) {
                    target.at(i).at(k) = '#';
                    target.at(j-1).at(k) = '#';
                    target.at(k).at(i) = '#';
                    target.at(k).at(j-1) = '#';
                }
            }
        }
    }

    rep(i, n) {
        rep (j, n) {
            cout << target.at(i).at(j);
        }
        cout << endl;
    }

    return 0;
}