#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve () {
    ll n, m; cin >> n >> m;
    string s; cin >> s;
    map <char, ll> mp;
    for (ll i = 0; i < 7; i++) mp['A' + i] = 0;
    for (ll i = 0; i < n; i++) mp[s[i]]++;

    ll ans = 0;

    for (auto it : mp) {
        if (it.second < m) ans += m - it.second;
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