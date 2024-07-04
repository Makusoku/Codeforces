#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve () {
    ll n; cin >> n;
    vector <ll> v(n);
    for (auto &it : v) cin >> it;
    if (n <= 2) {
        cout << *min_element(v.begin(), v.end()) << '\n'; 
        return;
    }
    ll ans = -1;
    for (ll i = 0; i < n - 2; i++) {
        vector <ll> vm;
        vm.emplace_back(v[i]);
        vm.emplace_back(v[i+1]);
        vm.emplace_back(v[i+2]);
        sort (vm.begin(), vm.end());
        ans = max (vm[1], ans);    
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