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

    int t;
    cin >> t;

    rep(_, t) {
        int n, w;
        cin >> n >> w;

        // あまりの値が同じものをグループ化する
        vector<ll> group(w*2, 0);
        rep (i, n) {
            int c;
            cin >> c;

            group.at(i%(w*2)) += c;
        }
        /*
        rep (i, group.size()) {
            cout << group.at(i) << ' ';
        }
        cout << endl;
        */

        // あまりの累積和の vector
        vector<ll> sum_rem;
        sum_rem.push_back(0);
        rep (i, w*2+w-1) {
            int index = i%(w*2);
            ll next_value = sum_rem.at(i) + group.at(index);
            sum_rem.push_back(next_value);
        }
        /*
        rep (i, sum_rem.size()) {
            cout << sum_rem.at(i) << ' ';
        }
        cout << endl;
        */

        // index の差が2の値を比較し、最小値を求める
        vector<ll> costs;
        rep (i, w*2) {
            ll cost = sum_rem.at(i+w) - sum_rem.at(i);
            costs.push_back(cost);
        }

        ll min_cost = *min_element(costs.begin(), costs.end());
        cout << min_cost << endl;
    }

    return 0;
}