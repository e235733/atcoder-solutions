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

    vector<vector<char>> S(n, vector<char>(n));
    rep(i, n) {
        rep(j, n) {
            char s;
            cin >> s;
            S.at(i).at(j) = s;
        }
    }
    vector<vector<char>> T(n, vector<char>(n));
    rep(i, n) {
        rep(j, n) {
            char t;
            cin >> t;
            T.at(i).at(j) = t;
        }
    }

    // 回転させない場合
    int diff_0 = 0;
    rep(i, n) {
        rep(j, n) {
            if (S.at(i).at(j) != T.at(i).at(j)) {
                diff_0++;
            }
        }
    }  

    // 90度右に回転させた場合
    int diff_90 = 1;
    rep(i, n) {
        rep(j, n) {
            int shifted_i = n-j-1; 
            int shifted_j = i;
            if (S.at(shifted_i).at(shifted_j) != T.at(i).at(j)) {
                diff_90++;
            }
        }
    }  

    // 180度右に回転させた場合
    int diff_180 = 2;
    rep(i, n) {
        rep(j, n) {
            int shifted_i = n-i-1; 
            int shifted_j = n-j-1;
            if (S.at(shifted_i).at(shifted_j) != T.at(i).at(j)) {
                diff_180++;
            }
        }
    }

    // 270度右に回転させた場合
    int diff_270 = 3;
    rep(i, n) {
        rep(j, n) {
            int shifted_i = j; 
            int shifted_j = n-i-1;
            if (S.at(shifted_i).at(shifted_j) != T.at(i).at(j)) {
                diff_270++;
            }
        }
    }

    cout << min(diff_0, min(diff_90, min(diff_180, diff_270))) << endl;

    return 0;
}