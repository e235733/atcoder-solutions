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

    vector<int> line;
    int head = 0;

    rep(_, q) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            line.push_back(x);
        }
        else {
            cout << line.at(head) << endl;
            head++;
        }
    }

    return 0;
}