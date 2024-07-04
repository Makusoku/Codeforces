#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve () {
    ll n; cin >> n;
    vector <ll> v(n); 
    for (auto &it : v) cin >> it;
    map <ll, ll> m;
    for (auto it : v) m[it]++;
    if (m.size() >= 3) {
        cout << "YES\n";
        cout << "R";
        for (ll i = 1; i < n; i++) cout << "B";
        cout << '\n';
    }
    else {
        if (m.size() == 1) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
            ll ind = 0;
            for (ll i = 0; i < n; i++) {
                if (v[i] != v[i + 1]) {ind = i; break;}
            }
            if (ind == 0) {
                cout << "BB";
                for (ll i = 2; i < n; i++) cout << "R";
                cout << '\n';
                return;
            }
            for (ll i = 0; i < n; i++) {
                if (i == ind) {
                    for (ll j = ind; j < n; j++) {
                        cout << "R";
                    }
                    cout << '\n';
                    return;
                }
                cout << "B";
            }
        }
    }
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll _ = 1;
    cin >> _;
    while (_--)
        solve ();
    return 0;
}