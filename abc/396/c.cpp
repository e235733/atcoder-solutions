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

    int n, m;
    cin >> n >> m;

    vector<int> B, W;

    rep(i, n) {
        int b;
        cin >> b;

        B.push_back(b);
    }
    rep(i, m) {
        int w;
        cin >> w;

        W.push_back(w);
    }

    // 降順にソートする
    sort(B.rbegin(), B.rend());
    sort(W.rbegin(), W.rend());

    // B においては最初から足していくことで、i 個以上選択したときの最大価値がわかる
    // 0 番目は 0 としておくことで、0 個選択した場合にも対応させる
    vector<ll> max_val_b(1, 0), max_val_w(1, 0);
    rep (i, n) {
        ll current_v = max_val_b.at(i) + B.at(i);
        max_val_b.push_back(current_v);
    }

    // W においては、直前より高かった場合にのみ足すことで、i 個以下選択した時の最大価値がわかる
    rep (i, m) {
        ll current_v = max_val_w.at(i) + W.at(i);
        // 直前より高かった場合のみ更新する
        if (current_v > max_val_w.at(i)) {
            max_val_w.push_back(current_v);
        }
        else {
            max_val_w.push_back(max_val_w.at(i));
        }
    }

    // n > m のときは、max_val_w の末尾の要素で埋め、長さを max_val_b と同じにする
    if (n > m) {
        rep (i, n-m) {
            max_val_w.push_back(max_val_w.back());
        }
    }

    // n 種類の選択バターンを試し、最大値を求める
    ll max_v = 0;
    rep (i, n+1) {
        ll current_v = max_val_b.at(i) + max_val_w.at(i);
        if (current_v > max_v) {
            max_v = current_v;
        }
    }

    cout << max_v << endl;
    
    return 0;
}