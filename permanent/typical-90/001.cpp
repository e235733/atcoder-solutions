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

    int n, l, k;
    cin >> n >> l >> k;

    // 各ようかんの長さ
    vector<int> A(n+1);
    cin >> A[0];
    int prev_a = A[0];
    rep (i, n-1) {
        int a;
        cin >> a;
        A[i+1] = a - prev_a;
        prev_a = a;
    }
    A[n] = l - prev_a;
    debug(A);
    
    // 2分探索する
    int min = 1;
    int max = l / (k + 1);
    while (min + 1 != max) {
        int mid = (min + max) / 2;
        debug(min, max, mid);
        int count = 0;
        int i = 0;
        // 長さ mid 以上で k + 1 個に分けられるか
        while (count != k + 1 && i != n + 1) {
            int current_size = 0;
            while (i != n + 1) {
                current_size += A[i];
                i++;
                if (current_size >= mid) {
                    count++;
                    break;
                }
            }
            debug(i, current_size);
        }
        debug(mid, count);
        if (count == k + 1) {
            min = mid;
        }
        else {
            max = mid;
        }
    }
    int count = 0;
    int i = 0;
    // 長さ max で k + 1 個に分けられるか
    while (count != k + 1 && i != n + 1) {
        int current_size = 0;
        while (i != n + 1) {
            current_size += A[i];
            i++;
            if (current_size >= max) {
                count++;
                break;
            }
        }
        debug(i, current_size);
    }
    debug(max, count);
    if (count == k + 1) {
        cout << max << '\n';
    }
    else {
        cout << min << '\n';
    }
    

    return 0;
}