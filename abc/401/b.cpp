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
    bool is_logged_in = false;

    int num_error = 0;
    rep(i, n) {
        string operation;
        cin >> operation;

        if (operation == "login") {
            is_logged_in = true;
        }

        else if (operation == "logout") {
            is_logged_in = false;
        }

        else if (operation == "private") {
            if (!is_logged_in) {
                num_error++;
            }
        }
    }

    cout << num_error << endl;

    return 0;
}