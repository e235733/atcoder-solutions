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

    vector<int> sq;
    int next_v = 1;
    int next_sqv = 1;
    while(next_sqv <= n) {
        sq.push_back(next_sqv);
        next_v++;
        next_sqv = pow(next_v, 2);
    } 

    rep(i, sq.size()){
        //cout << sq.at(i) << endl;
    }

    map<int, int> result_count;

    for (int i=0; i<sq.size()-1; i++) {
        for (int j = i+1; j<sq.size(); j++) {
            int next_result = sq.at(i) + sq.at(j);
            if (next_result <= n) {
                result_count[next_result]++;
            }
            else {
                break;
            }
        }
    }

    vector<int> results;
    for (pair<int, int> p : result_count) {
        //cout << p.first << ' ' << p.second << endl;
        if (p.second == 1) {
            results.push_back(p.first);
        }
    }

    cout << results.size() << endl;
    rep(i, results.size()){
        cout << results.at(i) << ' ';
    }
    cout << endl;

    return 0;
}