#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll num1, ll num2) {
    if (num2 == 0)
        return num1;
    return gcd(num2, num1 % num2);
}
 
ll lcm_of_array(vector<ll> arr) {
    ll lcm = arr[0];
    for (ll i = 1; i < arr.size(); i++) {
        ll num1 = lcm;
        ll num2 = arr[i];
        ll gcd_val = gcd(num1, num2);
        lcm = (lcm * arr[i]) / gcd_val;
    }
    return lcm;
}

void solve () {
    ll n; cin >> n;
    vector <ll> v(n); for (auto &it : v) cin >> it;
    ll mcm = lcm_of_array(v);
    vector <ll> ans;
    for (ll i = 0; i < n; i++) {
        ans.emplace_back(mcm/v[i]);
    }
    
    ll sum = 0;

    for (auto it : ans) sum += it;

    for (int i = 0; i < n; i++) {
        if (sum >= ans[i]*v[i]) {
            cout << "-1\n";
            return;
        }
    }
    for (auto it : ans) cout << it << " ";
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