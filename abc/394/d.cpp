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

    string S;
    cin >> S;

    // スタックで管理する
    stack<char> bucket_stack;
    // カラフル行列が成り立っているか
    bool is_colorful = true;

    rep (i, S.size()) {
        char s = S.at(i);
        // スタックが空の場合
        if (bucket_stack.empty()) {
            // s が閉じ括弧ならカラフル括弧列ではない
            if (s == ']' || s == ')' || s == '>') {
                is_colorful = false;
                break;
            }
            // 開きならスタックに追加する
            else {
                bucket_stack.push(s);
            }
        }
        // 空でない場合
        else {
            // s の種類ごとに場合分け
            // ']' の場合
            if (s == ']') {
                // スタックのトップが '[' なら削除対象
                if (bucket_stack.top() == '[') {
                    bucket_stack.pop();
                }
                // それ以外の場合、カラフル括弧列ではなくなる
                else {
                    is_colorful = false;
                    break;
                }
            }
            // 同様に、')' の場合
            else if (s == ')') {
                if (bucket_stack.top() == '(') {
                    bucket_stack.pop();
                }
                else {
                    is_colorful = false;
                    break;
                }
            }
            // 同様に、'>' の場合
            else if (s == '>') {
                if (bucket_stack.top() == '<') {
                    bucket_stack.pop();
                }
                else {
                    is_colorful = false;
                    break;
                }
            }
            // 開き括弧の場合、スタックに追加する
            else {
                bucket_stack.push(s);
            }
        }
    }

    // スタックが空でなければカラフル括弧列ではない
    if (!bucket_stack.empty()) {
        is_colorful = false;
    }

    if (is_colorful) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    return 0;
}