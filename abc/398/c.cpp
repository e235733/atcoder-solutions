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

    // それぞれの値がいくつあるか記録する map
    map<int, int> counts;
    // どの人がどの値を持っているかも vector で記録しておく
    vector<int> A;
    rep(i, n) {
        int a;
        cin >> a;
        counts[a]++;
        A.push_back(a);
    }

    // 値の大きいものから順に見ていき、個数が1のものを探す
    auto i = counts.rbegin();
    // 個数が1のものがなければ、-1のまま
    int max_value = -1;
    for (; i != counts.rend(); ++i) {
        if (i->second == 1) {
            max_value = i->first;
            break;
        }
    }

    if (max_value == -1) {
        cout << -1 << endl;
    }
    else {
        // max_value を持った人を探す
        rep(i, n) {
            if (max_value == A.at(i)) {
                cout << i+1 << endl;
                break;
            }
        }
    }

    return 0;
}