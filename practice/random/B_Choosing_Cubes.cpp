#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve () {
    ll n, f, k; cin >> n >> f >> k;
    vector <ll> v(n);
    for (auto &it : v) cin >> it;
    ll fav = v[f - 1];
    sort (v.begin(), v.end());
    

    int lw = lower_bound(v.begin(), v.end(), fav) - v.begin() - 1;
    int upt = upper_bound(v.begin(), v.end(), fav) - v.begin() - 1 - 1;
    reverse (v.begin(), v.end());

    //for (auto it : v) cout << it << " "; 
    //cout << " Ga " << fav << " " << n - lw - 1 << " " << n - upt - 1 << endl;
    lw = n - 1 - lw - 1;
    upt = n - 1 - upt - 1;
    ll aux = lw;
    lw = upt;
    upt = aux;
    if (k - 1 >= upt) cout << "YES\n";
    else if (k - 1 >= lw and k - 1 <= upt) cout << "MAYBE\n";
    else cout << "NO\n";
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