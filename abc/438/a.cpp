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

    int d, f;
    cin >> d >> f;

    // dを超えるまでfに7を足す
    int next_date = f;
    while(next_date <= d) {
        next_date += 7;
    }
    
    // 結果からdを引く
    int first_date = next_date - d;

    cout << first_date << endl;
}