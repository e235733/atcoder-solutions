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

    int n, k;
    string s;
    cin >> n >> k >> s;
    // o の登場回数を記録する
    int count_o = 0;
    // 確実に . になる場所は置き換えた文字列
    string replaced_dot_s = "";
    replaced_dot_s.push_back(s.at(0));
    if (s.at(0) == 'o') {
        count_o++;
    }
    for (int i=1; i<n; i++){
        if (s.at(i) == '?') {
            if (s.at(i-1) == 'o') {
                replaced_dot_s.push_back('.');
            }
            else {
                replaced_dot_s.push_back(s.at(i));
            }
        }
        else if (s.at(i) == 'o') {
            if (s.at(i-1) == '?') {
                replaced_dot_s.pop_back();
                replaced_dot_s.push_back('.');
                replaced_dot_s.push_back(s.at(i));
            }
            else {
                replaced_dot_s.push_back(s.at(i));
            }
            count_o++;
        }
        else {
            replaced_dot_s.push_back(s.at(i));
        }
    }

    /*
    rep(i, n) {
        cout << replaced_dot_s.at(i);
    }
    cout << endl;
    */

    // ? の列が続いているのかどうか
    bool is_continued = false;
    // ? に o を入れられる個数を記録する
    int capable_o = 0;
    int count_q = 0, head;
    // ? を a(奇数)と b(偶数)に置き換えた文字列
    string replaced_ab = "";

    rep(i, n) {
        if (replaced_dot_s.at(i) == '?') {
            if (is_continued) {
                count_q++;
            }
            else {
                is_continued = true;
                count_q = 1;
                head = i;
            }
        }
        else {
            if (is_continued) {
                // ? が続いた回数
                int num_constant = i - head;
                // 奇数回だった場合
                if (num_constant % 2 == 1) {
                    rep(_, num_constant) {
                        replaced_ab.push_back('a');
                    }
                }
                // 偶数回だった場合
                else {
                    rep(_, num_constant) {
                        replaced_ab.push_back('b');
                    }
                }
                // ? の連続にいくつの o が入るかを計算し、合計にたす
                capable_o += (num_constant + 1) / 2;

                replaced_ab.push_back(replaced_dot_s.at(i));
                is_continued = false;
            }
            else {
                replaced_ab.push_back(replaced_dot_s.at(i));
            }
        }
    }
    if (is_continued) {
        // ? が続いた回数
        int num_constant = n - head;
        // 奇数回だった場合
        if (num_constant % 2 == 1) {
            rep(_, num_constant) {
                replaced_ab.push_back('a');
            }
        }
        // 偶数回だった場合
        else {
            rep(_, num_constant) {
                replaced_ab.push_back('b');
            }
        }
        // ? の連続にいくつの o が入るかを計算し、合計にたす
        capable_o += (num_constant + 1) / 2;
    }

    /*
    rep(i, n) {
        cout << replaced_ab.at(i);
    }
    cout << endl;
    */

    //cout << count_o << ' ' << capable_o << endl;
    // 答えを保存する
    string t = "";
    // o の数が k と一致する場合
    if (count_o == k) {
        rep(i, n) {
            if (replaced_ab.at(i) == 'a' || replaced_ab.at(i) == 'b') {
                t.push_back('.');
            }
            else {
                t.push_back(replaced_ab.at(i));
            }
        }
    }
    // o の最大数が k と一致する場合
    else if (count_o + capable_o == k) {
        bool is_a_continued = false;
        bool is_oddnum = true;
        rep(i, n) {
            if (replaced_ab.at(i) == 'a') {
                if (is_a_continued) {
                    if (is_oddnum) {
                        t.push_back('o');
                        is_oddnum = false;
                    }
                    else {
                        t.push_back('.');
                        is_oddnum = true;
                    }
                }
                else {
                    t.push_back('o');
                    is_a_continued = true;
                    is_oddnum = false;
                }
            }
            else {
                if (is_a_continued) {
                    is_a_continued = false;
                }
                if (replaced_ab.at(i) == 'b') {
                    t.push_back('?');
                }
                else {
                    t.push_back(replaced_ab.at(i));
                }
            }
        }
    }
    else {
        rep(i, n) {
            if (replaced_ab.at(i) == 'a' || replaced_ab.at(i) == 'b') {
                t.push_back('?');
            }
            else {
                t.push_back(replaced_ab.at(i));
            }
        }
    }

    rep(i, n) {
        cout << t.at(i);
    }
    cout << endl;

    return 0;
}