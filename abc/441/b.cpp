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

    int n, m, q;
    string s, t;
    cin >> n >> m >> s >> t >> q;

    // それぞれで使われる文字を set で記録する
    set<char> takahashi;
    set<char> aoki;
    rep (i, n) {
        takahashi.insert(s.at(i));
    }
    rep (i, m) {
        aoki.insert(t.at(i));
    }

    // 各単語について調べる
    rep (i, q) {
        string w;
        cin >> w;

        // 高橋語または青木語であるか
        bool is_takahashi = true;
        bool is_aoki = true;
        rep(j, w.size()) {
            // 高橋語の文字ではないものが登場
            if (!takahashi.contains(w.at(j))) {
                is_takahashi = false;
            }
            // 青木語の文字以外が登場
            if (!aoki.contains(w.at(j))) {
                is_aoki = false;
            }
        }
        // 両方あり得る場合
        if (is_takahashi && is_aoki) {
            cout << "Unknown" << endl;
        }
        // 高橋語だけ考えられる場合
        else if (is_takahashi) {
            cout << "Takahashi" << endl;
        }
        // 青木語だけ考えられる場合
        else if (is_aoki) {
            cout << "Aoki" << endl;
        }
    }

    return 0;
}