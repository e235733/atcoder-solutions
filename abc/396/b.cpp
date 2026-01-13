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

    int q;
    cin >> q;

    // 100枚の0カードの山を vector で用意する
    vector<int> cards(100, 0);

    rep (i, q) {
        int type;
        cin >> type;
        
        // クエリタイプが1のとき
        if (type == 1) {
            int x;
            cin >> x;

            // vector の末尾に x を追加する
            cards.push_back(x);
        }
        // クエリタイプが2のとき
        else {
            // 末尾の要素を出力する
            cout << cards.back() << endl;
            // 末尾を削除する
            cards.pop_back();
        }
    }

    return 0;
}