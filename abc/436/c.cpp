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

    int n, m;
    cin >> n >> m;

    map<int, set<int>> block;

    int num_block = 0;

    rep(i, m) {
        int r, c;
        cin >> r >> c;
        //cout <<  "about " << r << ' ' << c << endl;

        if (block.count(r-1)) {
            if (block.at(r-1).count(c-1) || block.at(r-1).count(c) || block.at(r-1).count(c+1)) {
                //cout << "No" << endl;
                continue;
            }
        }
        if (block.count(r)) {
            if (block.at(r).count(c-1) || block.at(r).count(c) || block.at(r).count(c+1)) {
                //cout << "No" << endl;
                continue;
            }
        }
        if (block.count(r+1)) {
            if (block.at(r+1).count(c-1) || block.at(r+1).count(c) || block.at(r+1).count(c+1)) {
                //cout << "No" << endl;
                continue;
            }
        }
        if (block.count(r)) {
            block.at(r).insert(c); 
        }
        else {
            set<int> s;
            block[r] = s;
            block.at(r).insert(c);
        }
        num_block++;
        //cout << "Yes, num_block " << num_block << endl;
    }

    cout << num_block << endl;

    return 0;
}