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

    if (n == m) {
        vector<vector<int>> to(n+1);
        rep(_, m) {
            int a, b;
            cin >> a >> b;
            to.at(a).push_back(b);
            to.at(b).push_back(a);
        }
        
    }
    else {
        cout << "No" << endl;
    }

    return 0;
}