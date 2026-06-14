#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

void all_search(vector<ll> &A, vector<vector<ll>> &P, int k, int count, int l, int n, ll v) {
    if (count == k + 1) return;
    for (int i=l; i!=n; ++i) {
        v += A[i];
        P[count].push_back(v);
        all_search(A, P, k, count+1, i+1, n, v);
        v -= A[i];
    }
}

ll count_less(vector<ll> &pi, ll p) {
    return upper_bound(pi.begin(), pi.end(), p) - pi.begin();
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    int n, k;
    ll p;
    cin >> n >> k >> p;
    vector<ll> A(n);
    rep (i, n) {
        cin >> A[i];
    }

    if (k > n) {
        cout << 0 << '\n';
        return 0;
    }

    int border = n / 2;

    if (n <= border) {
        vector<vector<ll>> P(k+1);
        P[0].push_back(0);
        all_search(A, P, k, 1, 0, n, 0);
        
        sort(P[k].begin(), P[k].end()); 
        cout << count_less(P[k], p) << '\n';
        return 0;
    }

    vector<ll> B(n-border);
    rep (i, n-border) {
        B[i] = A.back();
        A.pop_back();
    }
    vector<vector<ll>> P(border+1), Q(n-border+1);
    P[0].push_back(0);
    Q[0].push_back(0);
    
    all_search(A, P, min(k, border), 1, 0, border, 0);
    all_search(B, Q, min(k, n-border), 1, 0, n-border, 0);

    rep(i, border+1) {
        sort(P[i].begin(), P[i].end());
    }

    ll result = 0;
    rep (i, n-border+1) {
        int rem_k = k - i;
        if (rem_k < 0 || rem_k > border) continue;
        
        for (ll j : Q[i]) {
            result += count_less(P[rem_k], p-j);
        }
    }
    cout << result << '\n';

    return 0;
}