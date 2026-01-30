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

    ll n;
    int m;
    cin >> n >> m;
    debug(n, m);

    // a と、交換時の減少量
    vector<pair<ll, ll>> dec(m);
    rep (i, m) {
        ll a, b;
        cin >> a >> b;
        dec[i].first = a;
        // 減少量
        dec[i].second = a - b;
    }

    // a_i 以下の、最小の減少量
    map<ll, ll> min_dec;
    rep (i, m) {
        ll a_i = dec[i].first;
        ll dec_i = dec[i].second;
        // すでに a_i が存在していれば比較
        if (min_dec.contains(a_i)) {
            min_dec[a_i] = min(min_dec[a_i], dec_i);
        }
        // 存在しなければ最小値として追加
        else {
            min_dec[a_i] = dec_i;
        }
    }
    debug(min_dec);

    ll prev_min = 1LL << 60;
    // 前から順に、それ以前の最小値と比較する
    for(auto it=min_dec.begin(); it!=min_dec.end(); ++it) {
        it->second = min(it->second, prev_min);
        prev_min = it->second;
    }
    debug(min_dec);

    ll count_sticker = 0;
    // n 以上の a を取得
    auto it = min_dec.lower_bound(n);
    debug(*it);
    while (true) {
        debug(n);
        // n 以上の a が存在しなかった場合
        if (it == min_dec.end()) {
            it--;
            // 交換可能な回数だけ交換する
            ll num_trade = (n - it->first) / it->second + 1;
            count_sticker += num_trade;
            n -= it->second * num_trade;
            // イテレータの更新
            it = min_dec.lower_bound(n);
            debug(num_trade, count_sticker);
            debug(*it);
        }
        else {
            debug(it->first);
            // n と a が一致している場合
            if (n == it->first) {
                count_sticker++;
                n -= it->second;
                it = min_dec.lower_bound(n);
                debug(count_sticker);
                debug(*it);
            }
            else {
                debug(*min_dec.begin());
                // 現在以下の a での交換方法がなければ終了
                if (it == min_dec.begin()) {
                    break;
                }
                it--;
                ll num_trade = (n - it->first) / it->second + 1;
                count_sticker += num_trade;
                n -= it->second * num_trade;
                it = min_dec.lower_bound(n);
                debug(num_trade, count_sticker);
                debug(*it);
            }
        }
    }
    cout << count_sticker << endl;

    return 0;
}