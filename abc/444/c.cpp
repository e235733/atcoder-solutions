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

    int n;
    cin >> n;
    debug(n);

    int max_l = 0;
    int min_l = 1000000000;
    vector<int> list_l(n);
    rep (i, n) {
        int l;
        cin >> l;
        max_l = max(l, max_l);
        min_l = min(l, min_l);
        list_l[i] = l;
    }
    debug(max_l);
    debug(min_l);
    debug(list_l);

    sort(list_l.begin(), list_l.end());

    vector<int> answer;
    
    // l = max_l + min_l の場合を考える
    // これは、n が偶数の場合にのみ発生する
    if (n % 2 == 0) {
        int pred_l = max_l + min_l;
        debug(pred_l);
        bool is_answer = true;
        rep (i, n/2) {
            if (list_l[i] + list_l[n-i-1] != pred_l) {
                is_answer = false;
                break;
            }
        }
        if (is_answer) {
            answer.push_back(pred_l);
        }
    }

    // l == max_l の場合を考える
    // list_l から max_l を除く
    while (list_l.back() == max_l) {
        list_l.pop_back();
    }
    debug(list_l);
    int len_list = list_l.size();
    // リストの長さが偶数の場合のみ
    if (len_list % 2 == 0) {
        int pred_l = max_l;
        debug(pred_l);
        bool is_answer = true;
        rep (i, len_list/2) {
            if (list_l[i] + list_l[len_list-i-1] != pred_l) {
                is_answer = false;
                break;
            }
        }
        if (is_answer) {
            answer.push_back(pred_l);
        }
    }

    while(!answer.empty()) {
        cout << answer.back() << ' ';
        answer.pop_back();
    }
    cout << endl;

    return 0;
}