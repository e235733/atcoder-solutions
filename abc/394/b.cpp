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

    // 長さと文字列の組み合わせ
    vector<pair<int, string>> length;

    rep (i, n) {
        string s;
        cin >> s;

        // length に追加していく
        length.push_back({s.size(), s});
    }

    // ソートする
    sort(length.begin(), length.end());

    // 順番に出力していく
    rep (i, n) {
        cout << length.at(i).second;
    }
    cout << endl;

    return 0;
}