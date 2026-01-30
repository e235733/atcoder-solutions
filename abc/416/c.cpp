#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

// 結合文字列を作成する再帰関数
void concatenate(vector<string> &concatenated, vector<string> &S,string prev_c, int num_c, int k, int n) {
    // 結合回数をインクリメント
    num_c++;
    // 最終回の場合
    if (num_c == k) {
        // 結合文字列を作成し、concatenated に格納
        rep (i, n) {
            string current_c = prev_c + S.at(i);
            concatenated.push_back(current_c);
        }
    }
    else {
        rep (i, n) {
            string current_c = prev_c + S.at(i);
            // 再帰呼び出し
            concatenate(concatenated, S, current_c, num_c, k, n);
        }
    }
    // 結合回数をデクリメント
    num_c--;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    int n, k, x;
    cin >> n >> k >> x;

    vector<string> S;
    rep (_, n) {
        string s;
        cin >> s;
        S.push_back(s);
    }
    debug(S);

    // 全ての結合文字列を作成する
    vector<string> concatenated;
    string prev_c = "";
    concatenate(concatenated, S, prev_c, 0, k, n);
    debug(concatenated);

    // 辞書順にソートする
    sort(concatenated.begin(), concatenated.end());
    debug(concatenated);

    cout << concatenated.at(x-1) << endl;

    return 0;
}