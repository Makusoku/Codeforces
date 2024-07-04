#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve () {
    ll n; cin >> n;
    vector <ll> v(n); for (auto &it : v) cin >> it;
    vector <ll> triple;
    ll ans = 0;
    map <array<ll, 3>, ll> m;
    
    for (ll i = 0; i < n - 2; i++) {

        ans += (m[{v[i + 0], 0, v[i + 2]}] + m[{0, v[i + 1], v[i + 2]}] + m[{v[i + 0], v[i + 1], 0}]) - 3*(m[{v[i + 0], v[i + 1], v[i + 2]}]);
        //if (ans == 1) cout << i << endl;
        m[{v[i + 0], v[i + 1], v[i + 2]}]++;
        m[{v[i + 0], 0, v[i + 2]}]++;
        m[{0, v[i + 1], v[i + 2]}]++;
        m[{v[i + 0], v[i + 1], 0}]++;
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