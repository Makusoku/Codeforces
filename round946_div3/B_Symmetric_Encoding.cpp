#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve () {
    ll n; cin >> n;
    string s; cin >> s;
    map <char, ll> m;
    for (auto it : s) m[it]++;
    vector <char> v;
    for (auto it : m) v.emplace_back(it.first);
    ll n_prima = v.size();
    sort (v.begin(), v.end());
    for (ll i = 0; i < n; i++) {
        auto it = lower_bound (v.begin(), v.end(), s[i]);
        ll ind = it - v.begin();
        cout << v[n_prima - ind - 1];
    }
    cout << '\n';
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