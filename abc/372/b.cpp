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

    int m;
    cin >> m;
    
    vector<int> result;
    int a = 0;
    while (m != 0) {
        if (m % 3 == 0) {
            m /= 3;
            a++;
        }
        else {
            result.push_back(a);
            m--;
        }
    }
    debug(result);

    cout << result.size() << '\n';
    for (int r : result) {
        cout << r << ' ';
    }
    cout << '\n';

    return 0;
}