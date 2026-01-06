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

    int n, prev_num;
    cin >> n >> prev_num;

    bool now_increasing = false;
    int prev_count_increase = 0;
    int current_count_increase = 0;
    ll count_result = 0;
    rep(i, n-1) {
        int current_num;
        cin >> current_num;
        if (current_num > prev_num) {
            if (now_increasing) {
                current_count_increase += 1;
            }
            else {
                current_count_increase = 1;
                now_increasing = true;
            }
        }
        else {
            if (now_increasing) {
                count_result += 1LL * prev_count_increase * current_count_increase;
                now_increasing = false;
                prev_count_increase = current_count_increase;
            }
        }
        prev_num = current_num;
        //cout << prev_count_increase << ' ' << current_count_increase << ' ' << count_result << endl;
    }
    if (now_increasing) {
        count_result += 1LL * prev_count_increase * current_count_increase;
    }

    cout << count_result << endl;

    return 0;
}