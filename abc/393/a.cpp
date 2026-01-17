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

    string s1, s2;
    cin >> s1 >> s2;

    if (s1 == "sick") {
        // 両者お腹を壊した場合
        if (s2 == "sick") {
            cout << 1 << endl;
        }
        // 高橋君だけお腹を壊した場合
        else {
            cout << 2 << endl;
        }
    }
    else {
        // 青木君だけがお腹を壊した場合
        if (s2 == "sick") {
            cout << 3 << endl;
        }
        // 両者お腹を壊していない場合
        else {
            cout << 4 << endl;
        }
    }

    return 0;
}