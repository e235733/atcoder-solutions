#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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

    int n, s, m, l;
    cin >> n >> s >> m >> l;

    int ans = 1<<30;

    int vs = 0;
    int cs = 0;
    while (cs < n) {
        int vm = vs;
        int cm = cs;
        while (cm < n) {
            int vl = vm;
            int cl = cm;
            while (cl < n) {
                
                vl += l;
                cl += 12;

                if (cl >= n) {
                    ans = min(ans, vl);
                }
            }

            vm += m;
            cm += 8;

            if (cm >= n) {
                ans = min(ans, vm);
            }
        }

        vs += s;
        cs += 6;

        if (cs >= n) {
            ans = min(ans, vs);
        }
    }

    cout << ans << '\n';

    return 0;
}