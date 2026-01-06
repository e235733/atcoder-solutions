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

    int n, d;
    cin >> n >> d;
    
    map<int, int> count;
    rep(i, n) {
        int a;
        cin >> a;
        count[a]++;
    }

    int result = 0;
    while (!count.empty()) {
        vector<int> chain;
        auto p = count.begin();
        int key = p->first;
        chain.push_back(count.at(key));
        count.erase(key);

        int next_key = key + d;
        while (count.count(next_key)) {
            chain.push_back(count.at(next_key));
            next_key += d;
        }
        /*
        cout << "chain: ";
        rep(i, chain.size()) {
            cout << chain.at(i) << ' ';
        }
        cout << endl;
        */

        if (chain.size() == 1) {
            //cout << "skip" << endl;
            continue;
        }
        else if (chain.size() == 2) {
            result += min(chain[0], chain[1]);
            //cout << "add smoller value" << endl;
        }
        else {
            //cout << "start DP" << endl;
            int sum = chain[0] + chain[1];
            vector<int> dp{0, chain[0], chain[1]};
            for(int i=2; i < chain.size(); i++) {
                //cout << "dp: " << dp.at(0) << ' ' << dp.at(1) << ' ' << dp.at(2) << endl;
                sum += chain[i];
                int next0 = dp[1];
                int next1 = dp[2];
                int next2 = max(dp[0], dp[1]) + chain.at(i);
                dp = {next0, next1, next2};
            }
            //cout << "dp result: " << dp.at(0) << ' ' << dp.at(1) << ' ' << dp.at(2) << endl;
            //cout << "sum: " << sum << ", max: " << max(dp[1], dp[2]) << endl;
            result += sum - max(dp[1], dp[2]);
        }
        //cout << "result: " << result << endl;
    }
    cout << result << endl;

    return 0;
}