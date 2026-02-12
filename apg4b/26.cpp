#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    map<char, int> ints;
    auto val_of = [&ints](char a){
        // 数値の場合
        if (a - '0' > 0 && a - '0' <= 10) {
            return a - '0';
        }
        // 変数の場合
        else {
            return ints[a];
        }
    };

    map<char, vector<int>> vecs;
    auto get_vec = [&vecs, &val_of]{
        vector<int> vec;
        char head;
        cin >> head;
        if (head == '[') {
            char divider;
            do {
                char a;
                cin >> a;
                vec.push_back(val_of(a));
                cin >> divider;
            } while (divider != ']');
        }
        else {
            vec = vecs[head];
        }
        return vec;
    };

    auto calculate_ints = [&val_of]{
        int result = 0;
        char op = '+';
        do {
            char a;
            cin >> a;
            if (op == '+') {
                result += val_of(a);
            }
            else {
                result -= val_of(a);
            }
            cin >> op;
        } while (op != ';');
        return result;
    };

    auto calculate_vecs = [&get_vec]{
        vector<int> result;
        int len_vec = 0;
        char op = '+';
        do {
            vector<int> vec = get_vec();
            if (result.size() == 0) {
                len_vec = vec.size();
                result = vector<int>(len_vec, 0);
            }
            debug(vec);
            if (op == '+') {
                rep (i, len_vec) {
                    result[i] += vec[i];
                }
            }
            else {
                rep (i, len_vec) {
                    result[i] -= vec[i];
                }
            }
            debug(result);
            cin >> op;
            debug(op);
        } while (op != ';');
        return result;
    };

    int n;
    cin >> n;

    rep (_, n) {
        string type;
        cin >> type;
        debug(type);

        if (type == "int") {
            char name, equal;
            cin >> name >> equal;
            debug(name, equal);
            ints[name] = calculate_ints();
        }
        else if (type == "print_int") {
            int result = calculate_ints();
            cout << result << endl;
        }
        else if (type == "vec") {
            char name, equal;
            cin >> name >> equal;
            debug(name, equal);

            vecs[name] = calculate_vecs();
        }
        else {
            vector<int> result = calculate_vecs();

            cout << "[ ";
            rep (i, result.size()) {
                cout << result[i] << ' ';
            }
            cout << ']' << endl;
        }
        debug(ints);
        debug(vecs);
    }

    return 0;
}