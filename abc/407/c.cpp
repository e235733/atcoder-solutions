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

    string s;
    cin >> s;

    int length = s.size();
    int prev_num = s.at(0) - '0';

    int count_b = 0;
    for (int i=1; i<length; i++) {
        //cout << s.at(i) << endl;
        int current_num = s.at(i) - '0';
        if (prev_num >= current_num) {
            count_b += prev_num - current_num;
        }
        else {
            count_b += prev_num + 10 - current_num;
        }
        //cout << prev_num << ' ' << current_num << ' ' << count_b << endl;
        prev_num = current_num;
    }
    count_b += s.at(length-1) - '0';

    int result = length + count_b;
    cout << result << endl;

    return 0;
}