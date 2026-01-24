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

    int h, w;
    cin >> h >> w;

    vector<string> S;
    // 黒の存在する範囲
    int top = h-1, bottom = 0, left = w - 1, right = 0;
    rep (i, h) {
        string s;
        cin >> s;
        rep (j, w) {
            // 黒の場合は、範囲を更新
            if (s.at(j) == '#') {
                top = min(i, top);
                bottom = max(i, bottom);
                left = min(j, left);
                right = max(j, right);
            }
        }
        S.push_back(s);
    }
    /*
    rep(i, h) {
        cout << S.at(i) << endl;
    }
    cout << top << ' ' << bottom << ' ' << left << ' ' << right << endl;
    */

    // 範囲の中に白が存在するか検査する
    bool is_no_white = true;
    for (int i=top; i!=bottom+1; ++i) {
        for (int j=left; j!=right+1; ++j) {
            // 白が存在したらフラグを変更して終了
            if (S.at(i).at(j) == '.') {
                is_no_white = false;
                break;
            }
        }
    }

    if (is_no_white) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    return 0;
}