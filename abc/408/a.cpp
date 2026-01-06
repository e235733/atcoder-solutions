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

    int n, s;
    cin >> n >> s;

    int current_time = 0;
    bool completed = true;

    rep(i, n) {
        int t;
        cin >> t;
        if (t-current_time > s) {
            completed = false;
            break;
        }
        else {
            current_time = t;
        }
    }

    if (completed) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    return 0;
}