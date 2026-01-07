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

    ll n, k;
    cin >> n >> k;

    if (n < k) {
        //cout << "n < k" << endl;
        cout << 1 << endl;
    }
    
    else if (n == k) {
        //cout << "n == k" << endl;
        cout << k << endl;
    }
    else {
        //cout << "n > k" << endl;
        vector<ll> A(k, 1);
        A.push_back(k);
        rep(i, n-k) {
            ll prev_sum = A.back() * 2 - A.at(i);
            if (prev_sum >= 1000000000) {
                prev_sum -= 1000000000;
            }
            else if (prev_sum < 0) {
                prev_sum += 1000000000;
            }
            A.push_back(prev_sum); 
        }

        cout << A.back() << endl;
    }

    return 0;
}