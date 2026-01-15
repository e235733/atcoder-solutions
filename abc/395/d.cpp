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

    // 鳩の所属群 鳩の番号とindex を対応させる
    // vector.at(pigeon) = flock_id
    vector<int> affilation(n+1);

    // 群 map.at(flock_id) = set<pigeon>
    map<int, set<int>> flocks;

    // 群の所在 map.at(flock_id) = nest
    map<int, int> location;

    // 巣にいる群 巣の番号と index を対応させる
    // vector.at(nest) = flock_id
    vector<int> nest(n+1);

    // それぞれの初期化
    rep(i, n) {
        affilation.at(i+1) = i;
        flocks[i] = {i+1};
        location[i] = i+1;
        nest.at(i+1) = i;
    }

    rep(i, q) {
        int type;
        cin >> type;
        
        if (type == 1) {
            //cout << "query type 1" << endl;
            int a, b;
            cin >> a >> b;

            // 元と移動先の群の id
            int origin = affilation.at(a);
            int destination = nest.at(b);
            // 所属群を変更する
            affilation.at(a) = destination;

            // 元の群から削除し、移動先の群に追加する
            flocks.at(origin).erase(a);
            flocks.at(destination).insert(a);
        }

        else if (type == 2) {
            //cout << "query type 2" << endl;
            int a, b;
            cin >> a >> b;

            int origin = nest.at(a);
            int destination = nest.at(b);

            // 群と巣 の関係だけを入れ替える
            location.at(origin) = b;
            location.at(destination) = a;
            nest.at(a) = destination;
            nest.at(b) = origin;
        }

        else {
            //cout<< "query type 3" << endl;
            int a;
            cin >> a;

            // 属する群を確認し、その群の所在を調べる
            int flock = affilation.at(a);
            cout << location.at(flock) << endl;
        }
    }

    return 0;
}