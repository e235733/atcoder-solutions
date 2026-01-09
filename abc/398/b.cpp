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

    // カードに書かれた値と枚数を記録する
    map<int, int> cm;
    rep (i, 7) {
        int a;
        cin >> a;

        cm[a]++;
    }

    // カードが2種類以上なければ No
    if (cm.size() < 2) {
        cout << "No" << endl;
    }
    else {
        // 種類ごとのカードの数だけ vector で記録
        vector<int> counts;
        for (auto p : cm) {
            counts.push_back(p.second);
        }
        // 降順に並べ替える
        sort(counts.rbegin(), counts.rend());

        if (counts.at(0) >= 3 && counts.at(1) >= 2) {
            cout << "Yes" << endl;
        } 
        else {
            cout << "No" << endl;
        }
    }

    return 0;
}