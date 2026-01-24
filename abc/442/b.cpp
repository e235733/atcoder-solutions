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

    int q;
    cin >> q;

    int volume = 0;
    bool is_playing;

    rep(i, q) {
        int a;
        cin >> a;

        // 数値ごとの処理
        if (a == 1) {
            volume++;
        }
        else if (a == 2) {
            if (volume != 0) {
                volume--;
            }
        }
        else {
            is_playing = !is_playing;
        }

        // 音量３以上で再生されているか
        if (volume >= 3 && is_playing) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }

    return 0;
}