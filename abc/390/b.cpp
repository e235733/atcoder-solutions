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

    int n;
    cin >> n;

    // n = 2 なら必ず成立
    if (n == 2) {
        cout << "Yes" << endl;
    }
    else {
        vector<int> A;
        rep (i, n) {
            int a;
            cin >> a;
            A.push_back(a);
        }

        // a_i+1 ** 2 = a_i * a_i+2 であることを確かめる
        // 左辺を left, 右辺を right とする
        bool is_gs = true;
        rep (i, n-2) {
            ll left = 1LL *  A.at(i+1) * A.at(i+1);
            ll right = 1LL * A.at(i) * A.at(i+2);
            // 異なっていればフラグを変更して終了
            if (left != right) {
                is_gs = false;
                break;
            }
        }

        if (is_gs) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }

    return 0;
}