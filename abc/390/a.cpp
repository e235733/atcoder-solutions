#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    vector<int> A;
    rep (i, 5) {
        int a;
        cin >> a;
        A.push_back(a);
    }

    // 正しい位置にある数
    vector<int> correct;
    // 誤った位置にある数
    vector<int> incorrect;
    rep(i, 5){
        if (A.at(i) == i + 1) {
            correct.push_back(A.at(i));
        }
        else{
            incorrect.push_back(A.at(i));
        }
    }

    // 誤った位置が二つで、それらが隣り合っていればいい
    if (incorrect.size() == 2) {
        if (abs(incorrect.at(0) - incorrect.at(1)) == 1) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    else {
        cout << "No" << endl;
    }

    return 0;
}