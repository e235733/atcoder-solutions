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

    vector<int> points;
    map<int, int> mp;

    rep(i, n) {
        int p;
        cin >> p;
        points.push_back(p);
        mp[p]++;
    }

    map<int, int> rank;
    int r = 1;
    for (auto it=mp.rbegin(); it!=mp.rend(); ++it) {
        rank.insert(make_pair(it->first, r));
        r += it->second;
    }

    rep(i, n) {
        cout << rank.at(points.at(i)) << endl;
    }

    return 0;
}