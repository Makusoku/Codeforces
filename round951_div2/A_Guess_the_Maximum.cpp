#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve () {
    ll n;
    cin >> n;
    vector <ll> v(n); for (auto &it : v) cin >> it;
    ll ans = 1e18;
    for (ll i = 0; i < n - 1; i++) {
        ans = min (max (v[i], v[i + 1]), ans);
    }
    cout << ans - 1 << '\n';
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