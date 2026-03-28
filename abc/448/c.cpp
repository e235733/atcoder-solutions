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

    int n, q;
    cin >> n >> q;
    vector<int> numbers(n+1);
    map<int, int> balls;
    rep (i, n) {
        int a;
        cin >> a;

        numbers[i+1] = a;
        balls[a]++;
    }
    debug(balls);

    rep (_, q) {
        int k;
        cin >> k;
        vector<int> B(k);
        rep (i, k) {
            int b;
            cin >> b;
            int num_b = numbers[b];

            balls[num_b]--;
            if (balls[num_b] == 0) {
                balls.erase(num_b);
            }

            B[i] = num_b;
        }
        debug(balls);

        cout << balls.begin()->first << '\n';

        rep (i, k) {
            balls[B[i]]++;
        }
        debug(balls);
    }


    return 0;
}