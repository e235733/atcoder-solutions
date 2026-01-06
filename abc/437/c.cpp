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

    rep(i, t) {
        int n;
        cin >> n;
        ll sum_p = 0;
        vector<int> cost(n);
        rep(j, n) {
            int w, p;
            cin >> w >> p;
            sum_p += p;
            cost.at(j) = w+p;
        }
        sort(cost.begin(), cost.end());
        int result = 0;
        rep(j, n) {
            if (sum_p >= cost.at(j)) {
                result += 1;
                sum_p -= cost.at(j);
            }
            else {
                break;
            }
        }
        cout << result << endl;
    }

    return 0;
}