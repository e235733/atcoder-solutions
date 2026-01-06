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

    int n, l;
    cin >> n >> l;

    /*
    for (auto [p, count] : freq) {
        cout << p << ' ' << count << endl;
    }
    */

    ll num_triangle = 0;
    if (l % 3 == 0) {
        int prev_p = 0;
        map<int, int> freq;
        freq[0]++;

        rep(i, n-1) {
            int d;
            cin >> d;
            int next_p = (prev_p + d) % l;
            freq[next_p]++;
            prev_p = next_p;
        }

        for (auto [apex1, count] : freq) {
            if (apex1 < l/3) {
                int num_apex1 = count; 
                int apex2 = apex1 + l/3;
                if (freq.count(apex2)) {
                    int num_apex2 = freq.at(apex2);
                    int apex3 = apex2 + l/3;
                    if (freq.count(apex3)) {
                        int num_apex3 = freq.at(apex3);
                        num_triangle += 1LL * num_apex1 * num_apex2 * num_apex3;
                    }
                }
            }
            else {
                break;
            }
        }
    }

    cout << num_triangle << endl;

    return 0;
}