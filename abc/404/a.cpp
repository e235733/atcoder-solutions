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

    string S;
    cin >> S;
    vector<bool> alphabet(26, false);
    int length = S.size();

    rep(i, length) {
        int char_v = S.at(i) - 'a';
        alphabet.at(char_v) = true;
    }

    rep(i, 26) {
        if (!alphabet.at(i)) {
            char c = 'a' + i;
            cout << c << endl;
            break;
        }
    }

    return 0;
}