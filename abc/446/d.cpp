#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    int n;
    cin >> n;

    // 最後の数値とそこまでの最大の部分列の長さ
    unordered_map<int, int> max_length;
    
    rep (i, n) {
        int a;
        cin >> a;

        if (max_length.contains(a-1)) {
            int length = max_length[a-1]+1;
            if (max_length.contains(a)) {
                max_length[a] = max(max_length[a], length);
            }
            else {
                max_length[a] = length;
            }
            max_length.erase(a-1);
        }
        else if (!max_length.contains(a)) {
            max_length[a] = 1;
        }
        debug(max_length);
    }

    int result = 0;
    for (auto p : max_length) {
        result = max(result, p.second);
    }
    cout << result << '\n';

    return 0;
}