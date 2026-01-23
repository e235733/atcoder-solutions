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

    int n, q;
    cin >> n >> q;

    // 鳩のいる巣
    vector<int> pigeon(1, 0);
    rep(i, n) {
        pigeon.push_back(i+1);
    }

    // 巣にいる鳩の数
    vector<int> nest(1, 0);
    rep(i, n) {
        nest.push_back(1);
    }

    // 複数羽いる巣の数
    int num_multi_nest = 0;

    rep (i, q) {
        // クエリタイプ
        int type;
        cin >> type;
        // タイプ１
        if (type == 1) {
            int p, h;
            cin >> p >> h;

            // 現在鳩がいる巣
            int location = pigeon.at(p);
            // 取り除く
            nest.at(location)--;
            if (nest.at(location) == 1) {
                num_multi_nest--;
            }

            // 追加する
            nest.at(h)++;
            if (nest.at(h) == 2) {
                num_multi_nest++;
            }

            pigeon.at(p) = h;
        }
        // タイプ２
        else {
            cout << num_multi_nest << endl;
        }
    }

    return 0;
}