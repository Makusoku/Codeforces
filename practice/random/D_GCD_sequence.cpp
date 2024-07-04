#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve () {
    ll n; cin >> n;
    vector <ll> v(n);
    for (auto &it : v) cin >> it;
    bool ok = true;
    ll ind = 0;
    for (ll i = 0; i < n - 2; i++) {
        if (__gcd(v[i], v[i + 1]) > __gcd (v[i + 1], v[i + 2])) {
            ind = i;
            ok = false;
            break;
        }
    }
    if (ok) {
        cout << "YES\n";
        return;
    }

    vector <ll> v1, v2, v3;
    for (ll i = 0; i < n; i++) {
        v1.emplace_back(v[i]);
        v2.emplace_back(v[i]);
        v3.emplace_back(v[i]);
    }

    // primer caso,
    v1.erase(v1.begin() + ind);
    ok = true;
    for (ll i = 0; i < n - 3; i++) {
        if (__gcd(v1[i], v1[i + 1]) > __gcd (v1[i + 1], v1[i + 2])) {
            ok = false;
            break;
        }
    }
    if (ok) {
        cout << "YES\n";
        return;
    }

    // 2do caso
    if (ind + 1 < n) {
        v2.erase(v2.begin() + ind + 1);
        ok = true;
        for (ll i = 0; i < n - 3; i++) {
            if (__gcd(v2[i], v2[i + 1]) > __gcd (v2[i + 1], v2[i + 2])) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "YES\n";
            return;
        }
    }
    // 3er caso
    if (ind + 2 < n) {
        v3.erase(v3.begin() + ind + 2);
        ok = true;
        for (ll i = 0; i < n - 3; i++) {
            if (__gcd(v3[i], v3[i + 1]) > __gcd (v3[i + 1], v3[i + 2])) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";


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