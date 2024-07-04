#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve () {
    ll n; cin >> n;
    vector <ll>  v(n); 
    for (auto &it : v) cin >> it;

    ll mn = *min_element (v.begin(), v.end());
    ll mx = *max_element (v.begin(), v.end());

    if (mx < 0) {
        cout << abs (accumulate(v.begin(), v.end(), 0LL)) << '\n';
        return;
    }
    if (mn >= 0) {
        cout << accumulate (v.begin(), v.end(), 0LL) << '\n';
        return;
    }

    ll ans = 0;
    for (ll i = n - 1; i >= 0; i--) {
        ans += v[i];
        if (i - 1 >= 0 and ans < 0 and abs (v[i - 1] + ans) < v[i - 1] + abs(ans) ) {
            ans = abs(ans);
        }
    }
    cout << abs(ans) << '\n';
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