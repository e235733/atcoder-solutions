#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    int n;
    cin >> n;

    vector<int> A;
    // ３、7の倍数をカウントする
    map<int, int> count_three, count_seven;
    // 合計をカウント
    ll result = 0;

    // j が最大の場合について調べる
    rep (i, n) {
        int a;
        cin >> a;
        A.push_back(a);
        //cout << "now about: " << a << endl;

        // 3の約数の場合
        if (a % 3 == 0) {
            //cout << "this is dividable by 3" << endl;
            int quotient = a / 3;
            // 個数をインクリメント
            count_three[quotient]++;
        }
        // 7の約数の場合
        if (a % 7 == 0) {
            //cout << "this is dividable by 7" << endl;
            int quotient = a / 7;
            count_seven[quotient]++;
        }

        /*
        cout << "map state:" << endl;
        cout << "count_three: { ";
        for (auto ct : count_three) {
            cout << ct.first << ": " << ct.second << ", ";
        }
        cout << " }" << endl;
        cout << "count_seven: { ";
        for (auto cs : count_seven) {
            cout << cs.first << ": " << cs.second << ", ";
        }
        cout << " }" << endl;
        */

        // 5の約数の場合
        if (a % 5 == 0) {
            //cout << "this is dividable by 5" << endl;
            int quotient = a / 5;
            // 同じ商になる値の存在を確認
            if (count_three.contains(quotient) && count_seven.contains(quotient)) {
                // 組み合わせの個数を調べ、計上する
                ll combinations = 1LL * count_three.at(quotient) * count_seven.at(quotient);
                //cout << "combinations: " << combinations << endl;
                result += combinations;
            }
        }
    }

    // map の中身をリセット
    count_three = {};
    count_seven = {};

    // j が最小の場合について調べる
    rep (i, n) {
        int a = A.at(n-1-i);
        //cout << "now about: " << a << endl;

        // 3の約数の場合
        if (a % 3 == 0) {
            //cout << "this is dividable by 3" << endl;
            int quotient = a / 3;
            // 個数をインクリメント
            count_three[quotient]++;
        }
        // 7の約数の場合
        if (a % 7 == 0) {
            //cout << "this is dividable by 7" << endl;
            int quotient = a / 7;
            count_seven[quotient]++;
        }
        /*
        cout << "map state:" << endl;
        cout << "count_three: { ";
        for (auto ct : count_three) {
            cout << ct.first << ": " << ct.second << ", ";
        }
        cout << " }" << endl;
        cout << "count_seven: { ";
        for (auto cs : count_seven) {
            cout << cs.first << ": " << cs.second << ", ";
        }
        cout << " }" << endl;
        */

        // 5の約数の場合
        if (a % 5 == 0) {
            //cout << "this is dividable by 5" << endl;
            int quotient = a / 5;
            // 同じ商になる値の存在を確認
            if (count_three.contains(quotient) && count_seven.contains(quotient)) {
                // 組み合わせの個数を調べ、計上する
                ll combinations = 1LL * count_three.at(quotient) * count_seven.at(quotient);
                //cout << "combinations: " << combinations << endl;
                result += combinations;
            }
        }
    }

    cout << result << endl;

    return 0;
}