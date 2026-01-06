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

    string n;
    cin >> n;

    set<string> numbers;
    string current_n = n;
    bool is_lucky = false;

    while (true) {
        if (current_n == "1") {
            is_lucky = true;
            break;
        }
        if (numbers.count(current_n))
            break;
        else {
            numbers.insert(current_n);
            int length = current_n.size();

            int next_n = 0;
            rep(i, length){
                //cout << current_n.at(i) << endl;
                next_n += pow((int)(current_n.at(i) - '0'), 2);
            }
            //cout << next_n << endl;
            current_n = to_string(next_n);
        }
    }
    if (is_lucky) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    return 0;
}