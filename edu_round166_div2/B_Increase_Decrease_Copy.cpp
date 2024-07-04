#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve () {
    ll n; cin >> n;
    vector <ll> a(n); for (auto &it : a) cin >> it;
    vector <ll> b(n + 1); for (auto &it : b) cin >> it;
    bool ok = false;

    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        ans += abs (a[i] - b[i]);
    }
    for (ll i = 0; i < n; i++) {
        if (a[i] == b[n]) ok = true;
    }
    if (ok) ans++;
    else {
        ok = false;
        for (ll i = 0; i < n; i++) {
            if (b[n] <= max (a[i], b[i]) and b[n] >= min (a[i], b[i])) ok = true;
        }
        if (ok) ans++;
        else {
            ans++;
            ll mn = 1e18;
            for (ll i = 0; i < n; i++) {
                mn = min (mn, min (abs(b[n] - a[i]), abs(b[n] - b[i])));
            }
            ans += mn;
        }
    }
    cout << ans << '\n';
 
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