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
    map<int, int, greater<int>> freq;

    rep(i, n) {
        int val;
        cin >> val;
        freq[val]++;
    }

    int sum_count = 0;
    int max_count = 0;
    for (auto [num, count] : freq) {
        sum_count += count;
        //cout << "num:" << num << ' ' << "count:" << count << endl;
        //cout << "sum_count:" << sum_count << endl;
        if (num >= sum_count) {
            max_count = sum_count;
        }
        else {
            if (min(num, sum_count) > max_count) {
                max_count = min(num, sum_count);
            }
            break;
        }
    }

    cout << max_count << endl;

    return 0;
}