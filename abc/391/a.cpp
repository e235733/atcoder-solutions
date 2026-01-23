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

    string d;
    cin >> d;

    string od = "";

    for (char c : d) {
        if (c == 'N') {
            od += 'S';
        }
        else if (c == 'S') {
            od += 'N';
        }
        else if (c == 'E') {
            od += 'W';
        }
        else {
            od += 'E';
        }
    }
    
    cout << od << endl;

    return 0;
}