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

    // 登場する数値を記録し、それぞれの最初と最後の位置を記録
    // {(数値) : {最初, 最後}}
    map<int, pair<int, int>> appearPosition;

    rep (i, n) {
        int a;
        cin >> a;

        if (appearPosition.contains(a)) {
            appearPosition[a].second = i;
        }
        else {
            // 1回目の登場は、最初と最後の位置が同じ
            appearPosition[a] = {i, i};
        }
    }

    // いもす法を利用するために、両端を記録する
    vector<int> imos(n, 0);

    for (auto p : appearPosition) {
        int first_i = p.second.first;
        int last_i = p.second.second;
        //cout << p.first << " : {" << p.second.first << ", " << p.second.second << "}" << endl;
        
        // 複数回登場する、すなわち最初と最後が違う場合のみ記録する
        if (first_i != last_i) {
            imos.at(first_i)++;
            imos.at(last_i)--;
        }
    }

    // 分割の前後で種類をいくつ増やせるかをスコアとする
    vector<int> scores;
    int prev_score = 0;

    rep (i, n) {
        int current_score = prev_score + imos.at(i);
        scores.push_back(current_score);
        //cout << current_score << ' ';
        prev_score = current_score;
    }

    // 解答は、数値の種数とスコアの最大値を足したもの
    int count_num_type = appearPosition.size();
    int max_score = *max_element(scores.begin(), scores.end());
    int result = count_num_type + max_score;

    cout << result << endl;

    return 0;
}