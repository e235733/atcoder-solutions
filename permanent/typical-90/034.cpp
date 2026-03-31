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

    int n, k;
    cin >> n >> k;

    vector<int> A(n);
    rep (i, n) {
        cin >> A[i];
    }

    // 尺取り法で求める
    int l = 0;
    int r = 0;
    unordered_map<int, int> count;
    count[A[l]]++;
    int max_length = 0;
    while (r != n) {
        debug(l, r);
        debug(count);
        if ((int)count.size() > k) {
            count[A[l]]--;
            if (count[A[l]] == 0) {
                count.erase(A[l]);
            }
            l++;
        }
        else {
            int length = r - l + 1;
            max_length = max(length, max_length);
            r++;
            count[A[r]]++;
        }
    }

    cout << max_length << '\n';

    return 0;
}