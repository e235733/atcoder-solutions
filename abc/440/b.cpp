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

    map<int, int> times;
    rep(i, n) {
        int t;
        cin >> t;

        times[t] = i+1;
    }

    int count = 0;
    for (auto it=times.begin(); it!=times.end() && count!=3; ++it) {
        cout << it->second << ' ';
        count++;
    }
    cout << endl;

    return 0;
}