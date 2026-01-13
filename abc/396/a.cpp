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

    int n;
    cin >> n;

    vector<int> A;
    rep (i, n) {
        int a;
        cin >> a;
        A.push_back(a);
    }

    int before1v = A.at(1);
    int before2v = A.at(0);

    bool isExist = false;

    rep(i, n-2) {
        int currentV = A.at(i+2);
        if (before1v == before2v) {
            if (before1v == currentV) {
                isExist = true;
                break;
            }
        }

        before2v = before1v;
        before1v = currentV;
    }

    if (isExist) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    return 0;
}