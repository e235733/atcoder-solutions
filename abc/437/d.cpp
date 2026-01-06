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

    map<int, int> freq_A; // Aの値ごとの登場回数
    ll sum_A = 0; // 全てのAの合計
    rep(i, n) {
        int a;
        cin >> a;
        freq_A[a]++;
        sum_A += a;
    }

    map<int, int> freq_B; // Bの値ごとの登場回数
    ll sum_B = 0; // 全てのBの合計
    rep(i, m) {
        int b;
        cin >> b;
        freq_B[b]++;
        sum_B += b;
    }

    map<int, pair<int, ll>> sum_a_to_end; // 登場したAの特定の値から最高値までの合計
    int num_a_to_end = n; 
    sum_a_to_end[0] = {num_a_to_end, sum_A};
    //cout << sum_A << endl;
    ll prev_sum = sum_A;
    for (auto ap : freq_A) {
        int current_value = ap.first;
        int current_num = ap.second;
        ll current_sum = prev_sum - 1LL * current_value * current_num;

        num_a_to_end -= current_num;
        sum_a_to_end[current_value] = {num_a_to_end, current_sum}; 
        //cout << num_a_to_end << ' ' << current_sum << endl;
        prev_sum = current_sum;
    }
    
    // Bについて小さい順に差を合算していく
    ll sum_diff = 0;
    for (auto bp : freq_B) {
        int value_b = bp.first;
        int num_b = bp.second;
        int prev_value_a = 0;
        //cout << "about " << value_b << endl;

        bool b_over_a = true;
        for (auto app : sum_a_to_end) {
            int value_a = app.first;
            //cout << "with " << value_a << endl;
            if (value_a == 0) {
                continue;
            }
            else if (value_a >= value_b) {
                //cout << "a >= b" << endl;
                // bより左側の和を求める
                ll left_sum = sum_a_to_end.at(0).second - sum_a_to_end.at(prev_value_a).second;
                int left_num = sum_a_to_end.at(0).first - sum_a_to_end.at(prev_value_a).first;
                ll left_diff_sum = 1LL * value_b * left_num - left_sum;
                // bより右側の和を求める
                ll right_sum = sum_a_to_end.at(prev_value_a).second;
                int right_num = sum_a_to_end.at(prev_value_a).first;
                ll right_diff_sum = right_sum - 1LL * value_b * right_num;

                //cout << "left_diff_sum:" << left_diff_sum << ", right_diff_sum:" << right_diff_sum << endl;
                sum_diff += (left_diff_sum + right_diff_sum) * num_b;
                sum_diff %= 998244353;
                b_over_a = false;
                break;
            }
            else {
                if (prev_value_a != 0) {
                    sum_a_to_end.erase(prev_value_a);
                    //cout << "deleted_key:" << prev_value_a << endl;
                }
                prev_value_a = value_a;
            }
        }
        if (b_over_a) {
            cout << "b > a" << endl;
            sum_diff += (1LL * value_b * sum_a_to_end.at(0).first - sum_a_to_end.at(0).second) * num_b;
            sum_diff %= 998244353;
        }
        //cout << "sum_diff:" << sum_diff << endl;
    }

    cout << sum_diff << endl;

    return 0;
}