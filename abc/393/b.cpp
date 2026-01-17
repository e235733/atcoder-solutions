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

    int count = 0;

    // 全探索する
    rep (i, s.size()-2) {
        if (s.at(i) == 'A') {
            // A と B の距離を dist とすると、i + dist * 2 が s の最大インデックスを超えてはいけない
            int dist = (s.size() - i - 1) / 2;
            rep (j, dist) {
                if (s.at(i+j+1) == 'B') {
                    if (s.at(i+(j+1)*2) == 'C') {
                        count++;
                    }
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}