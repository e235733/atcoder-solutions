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

    int h, w;
    cin >> h >> w;
    vector A(h, vector<int>(w)), B(h, vector<int>(w));
    rep (i, h) {
        rep (j, w) {
            cin >> A[i][j];
        }
    }
    rep (i, h) {
        rep (j, w) {
            cin >> B[i][j];
        }
    }

    int ns = 1;
    rep (_, w) {
        ns *= w;
    }
    rep (_, h) {
        ns *= h;
    }
    debug(ns);

    vector<int> sw0(w), sh0(h);
    rep (i, w) {
        sw0[i] = i;
    }
    rep (i, h) {
        sh0[i] = i;
    }
    debug(sw0, sh0);

    int v0 = 0;
    rep (i, w) {
        v0 *= w;
        v0 += sw0[i];
    }
    rep (i, h) {
        v0 *= h;
        v0 += sh0[i];
    }
    debug(v0);

    vector<int> cs = {v0};
    vector<bool> used(ns, false);
    used[v0] = true;
    int count = 0;
    while (cs.size()) {
        debug(count);
        vector<int> ns;
        for (int v : cs) {
            vector<int> sw(w), sh(h);
            rep (i, h) {
                sh[h-i-1] = v % h;
                v /= h;
            }
            rep (i, w) {
                sw[w-i-1] = v % w;
                v /= w;
            }
            debug(sw, sh);

            bool ok = true;
            rep (r, h) {
                rep (c, w) {
                    if (A[sh[r]][sw[c]] != B[r][c]) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) break;
            }

            if (ok) {
                cout << count << '\n';
                return 0;
            }

            rep (i, h-1) {
                swap(sh[i], sh[i+1]);

                int nv = 0;
                rep (k, w) {
                    nv *= w;
                    nv += sw[k];
                }
                rep (k, h) {
                    nv *= h;
                    nv += sh[k];
                }
                //debug(nv);

                if (!used[nv]) {
                    ns.push_back(nv);
                    used[nv] = true;
                }

                swap(sh[i], sh[i+1]);
            }
            rep (j, w-1) {
                swap(sw[j], sw[j+1]);

                int nv = 0;
                rep (k, w) {
                    nv *= w;
                    nv += sw[k];
                }
                rep (k, h) {
                    nv *= h;
                    nv += sh[k];
                }
                //debug(nv);

                if (!used[nv]) {
                    ns.push_back(nv);
                    used[nv] = true;
                }

                swap(sw[j], sw[j+1]);
            }
        }
        ++count;
        swap(ns, cs);
    }

    cout << -1 << '\n';
    
    return 0;
}