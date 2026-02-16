#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

void generate_all(vector<string> &all, string prev, int length) {
    int prev_len = prev.size();
    if (prev_len == length) {
        all.push_back(prev);
    }
    else {
        string current = prev + '(';
        generate_all(all, current, length);
        current = prev + ')';
        generate_all(all, current, length);
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    int n;
    cin >> n;

    // 長さが奇数なら即終了
    if (n % 2 == 1) {
        return 0;
    }

    // パターンをすべて列挙する
    vector<string> all;
    generate_all(all, "", n);
    debug(all);

    // 矛盾がないものを出力する
    for (string s : all) {
        debug(s);
        stack<char> buckets;
        bool is_ok = true;
        rep (i, n) {
            debug(s[i]);
            if (s[i] == '(') {
                buckets.push(s[i]);
            }
            else {
                if (buckets.empty()) {
                    is_ok = false;
                    break;
                }
                else {
                    buckets.pop();
                }
            }
        }
        debug(buckets);
        if (buckets.empty() && is_ok) {
            cout << s << '\n';
        }
    }

    return 0;
}