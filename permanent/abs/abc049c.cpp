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

    string s;
    cin >> s;
    int len_s = s.size();
    debug(len_s);

    // 直前が単語の終わりである
    bool is_end = true;
    // 単語の進捗
    string word = "";

    rep (i, len_s) {
        debug(s[i]);
        switch (s[i]) {
            case 'd':
                if (is_end) {
                    is_end = false;
                    word = "d";
                }
                else {
                    cout << "NO" << endl;
                    return 0;
                }
                break;
            case 'r':
                if (!is_end) {
                    if (word == "d" || word == "e") {
                        word += s[i];
                    }
                    else if (word == "dreame") {
                        is_end = true;
                        word += s[i];
                    }
                    else {
                        cout << "NO" << endl;
                        return 0;
                    }
                }
                else {
                    if (word == "erase") {
                        word = "";
                    }
                }
                break;
            case 'e':
                if (is_end) {
                    if (word == "dream") {
                        is_end = false;
                        word += s[i];
                    }
                    else {
                        is_end = false;
                        word = "e";
                    }
                }
                else {
                    if (word == "dr") {
                        word += s[i];
                    }
                    else if (word == "eras") {
                        is_end = true;
                        word += s[i];
                    }
                    else {
                        cout << "NO" << endl;
                        return 0;
                    }
                }
                break;
            case 'a':
                if (word == "dre" || word == "er") {
                    word += s[i];
                }
                else if (word == "dreamer") {
                    is_end = false;
                    word = "era";
                }
                else {
                    cout << "NO" << endl;
                    return 0;
                }
                break;
            case 'm':
                if (word == "drea") {
                    is_end = true;
                    word += s[i];
                }
                else {
                    cout << "NO" << endl;
                    return 0;
                }
                break;
            case 's':
                if (word == "era") {
                    word += s[i];
                }
                else {
                    cout << "NO" << endl;
                    return 0;
                }
                break;
        }
        debug(word);
        debug(is_end);
    }
    if (is_end) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}