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

    int h, w;
    cin >> h >> w;
    vector<vector<char>> M(h, vector<char>(w));
    // 次に探索するべきところを保持する
    queue<pair<int, int>> prev_visited;
    rep(i, h) {
        rep(j, w) {
            char c;
            cin >> c;
            M.at(i).at(j) = c;
            if (c == 'E') {
                prev_visited.push({i, j});
                //cout << i << ' ' << j << " is E" << endl;
            }
        }
    }

    while (prev_visited.size() > 0) {

        queue<pair<int, int>> current_visit;
        while(prev_visited.size() > 0) {
            int prev_i = prev_visited.front().first;
            int prev_j = prev_visited.front().second;
            //cout << "now about " << prev_i << ' ' << prev_j << endl;

            if (prev_i != 0) {
                if (M.at(prev_i-1).at(prev_j) == '.'){
                    M.at(prev_i-1).at(prev_j) = 'v';
                    current_visit.push({prev_i-1, prev_j});
                }
            }
            if (prev_i != h-1) {
                if (M.at(prev_i+1).at(prev_j) == '.'){
                    M.at(prev_i+1).at(prev_j) = '^';
                    current_visit.push({prev_i+1, prev_j});
                }
            }
            if (prev_j != 0) {
                if (M.at(prev_i).at(prev_j-1) == '.'){
                    M.at(prev_i).at(prev_j-1) = '>';
                    current_visit.push({prev_i, prev_j-1});
                }
            }if (prev_j != w-1) {
                if (M.at(prev_i).at(prev_j+1) == '.'){
                    M.at(prev_i).at(prev_j+1) = '<';
                    current_visit.push({prev_i, prev_j+1});
                }
            }
            prev_visited.pop();
        }
        prev_visited = current_visit;    

    }
    rep(i, h) {
        rep(j, w) {
            cout << M.at(i).at(j);
        }
        cout << endl;
    }   


    return 0;
}