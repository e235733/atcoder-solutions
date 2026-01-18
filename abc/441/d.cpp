#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

// recursive function
void dfs(vector<vector<pair<int, int>>>& g, vector<pair<int, int>>& to, set<int>& satisfying, int& sum_cost, int& floor, int& ceiling, int& target_depth, int current_depth) {

    current_depth++;
    //cout << "current depth: " << current_depth << endl;
    for (auto p : to) {
        sum_cost += p.second;
        //cout << "to: " << p.first << endl;
        // reach check
        if (current_depth == target_depth) {
            //cout << "reaching! sum cost: " << sum_cost << endl;
            // satisfy check
            if (sum_cost >= floor && sum_cost <= ceiling) {
                //cout << "satisfying!" << endl;
                satisfying.insert(p.first);
            }
        }
        else {
            //cout << "go deeper" << endl;
            // recursion
            dfs(g, g.at(p.first), satisfying, sum_cost, floor, ceiling, target_depth, current_depth);
        }
        sum_cost -= p.second;
    }
    current_depth--;
    //cout << "go shallower" << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    int n, m, l, s, t;
    cin >> n >> m >> l >> s >> t;

    // vector as of vertices and costs
    vector<vector<pair<int, int>>> g(n+1);
    rep (i, m) {
        int u, v, c;
        cin >> u >> v >> c;

        g.at(u).push_back({v, c});
    }

    set<int> satisfying; 

    int sum_cost = 0;

    // start exploration
    dfs(g, g.at(1), satisfying, sum_cost, s, t, l, 0);

    for (int a : satisfying) {
        cout << a << ' ';
    }
    cout << endl;

    return 0;
}