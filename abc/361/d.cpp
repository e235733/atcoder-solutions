#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

int n;
string s, t;

set<string> p;
vector<string> cs;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    cin >> n >> s >> t;
    if (s == t) {
        cout << 0 << '\n';
        return 0;
    }
    s += "..";
    t += "..";

    p.insert(s);
    cs.push_back(s);
    int count = 1;
    while (cs.size()) {
        debug(cs);
        vector<string> ns;
        for (string si : cs) {
            int ib = -1;
            rep (i, n+2) {
                if (si[i] == '.') {
                    ib = i;
                    break;
                }
            }
            debug(si, ib);

            if (ib >= 2) {
                rep (i, ib-1) {
                    string ps = "";
                    ps.reserve(n);
                    rep (j, i) ps.push_back(si[j]);
                    ps.push_back('.');
                    ps.push_back('.');
                    for (int j=i+2; j!=ib; ++j) ps.push_back(si[j]);
                    ps.push_back(si[i]);
                    ps.push_back(si[i+1]);
                    for (int j=ib+2; j!=n+2; ++j) ps.push_back(si[j]);
                    debug(ps);

                    if (!p.contains(ps)) {
                        if (ps == t) {
                            cout << count << '\n';
                            return 0;
                        }
                        p.insert(ps);
                        ns.push_back(ps);
                    }
                }
            }
            if (ib < n-1) {
                for (int i=ib+2; i!=n+1; ++i) {
                    string ps = "";
                    ps.reserve(n);
                    rep (j, ib) ps.push_back(si[j]);
                    ps.push_back(si[i]);
                    ps.push_back(si[i+1]);
                    for (int j=ib+2; j!=i; ++j) ps.push_back(si[j]);
                    ps.push_back('.');
                    ps.push_back('.');
                    for (int j=i+2; j!=n+2; ++j) ps.push_back(si[j]);
                    debug(ps);

                    if (!p.contains(ps)) {
                        if (ps == t) {
                            cout << count << '\n';
                            return 0;
                        }
                        p.insert(ps);
                        ns.push_back(ps);
                    }
                }
            }
        }
        cs = ns;
        count++;
    }

    cout << -1 << '\n';

    return 0;
}