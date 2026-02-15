#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    int h, w, n;
    cin >> h >> w >> n;

    // i と高さ・幅の関係、高さ・幅と i の関係
    vector<pair<int, int>> c(n), hi(n), wi(n);
    rep (i, n) {
        int h, w;
        cin >> h >> w;
        c[i] = {h, w};
        hi[i] = {h, i};
        wi[i] = {w, i};
    }
    debug(c);

    // 昇順にソートする
    sort(hi.begin(), hi.end());
    sort(wi.begin(), wi.end());
    debug(hi);
    debug(wi);

    // 使用済み
    vector<bool> is_used(n, false);
    int most_top = 1;
    int most_left = 1;

    vector<pair<int, int>> result(n);
    while (most_top != h+1 && most_left != w+1) {
        // すでに使われていたら削除する
        int back_hi = hi.back().second;
        while (is_used[back_hi]) {
            hi.pop_back();
            back_hi = hi.back().second;
        }
        int back_wi = wi.back().second;
        while (is_used[back_wi]) {
            wi.pop_back();
            back_wi = wi.back().second;
        }
        debug(hi);
        debug(wi);

        int max_h = hi.back().first;
        int max_w = wi.back().first;
        int left_h = h + 1 - most_top;
        int left_w = w + 1 - most_left;
        debug(max_h, max_w);
        debug(left_h, left_w);

        if (max_h == left_h) {
            int ans_i = hi.back().second;
            debug(ans_i);
            result[ans_i] = {most_top, most_left};
            most_left += c[ans_i].second;
            hi.pop_back();
            is_used[ans_i] = true;
        }
        else if (max_w == left_w) {
            int ans_i = wi.back().second;
            debug(ans_i);
            result[ans_i] = {most_top, most_left};
            most_top += c[ans_i].first;
            wi.pop_back();
            is_used[ans_i] = true;
        }
        debug(most_top, most_left);
        debug(is_used);
    }

    rep (i, n) {
        cout << result[i].first << ' ' << result[i].second << endl;
    }

    return 0;
}