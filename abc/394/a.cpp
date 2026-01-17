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

    string s;
    cin >> s;

    // 空の文字列を用意する
    string result = "";
    
    // 文字列の長さ分だけ繰り返す
    rep (i, s.size()) {
        // 文字が 2 であれば、結果に追加していく
        if (s.at(i) == '2') {
            result += '2';
        }
    }

    cout << result << endl;

    return 0;
}