#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve () {
    ll n; cin >> n;
    vector <ll> a(n); 
    for (auto &it : a) cin >> it;
    vector <ll> b(n);
    for (auto &it : b) cin >> it;
    ll m; cin >> m;
    vector <ll> d(m);
    for (auto &it : d) cin >> it;

    map <ll, ll> mp;
    vector <ll> v;
    
    for (ll i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            mp[b[i]]++;    
        }
        if (a[i] == b[i] or a[i] != b[i]) {
            v.emplace_back(b[i]);
        }
    }

    sort (v.begin(), v.end());

    bool ok = false;
    for (ll i = 0; i < m; i++) {
        if (binary_search(v.begin(), v.end(), d[i])) {
            mp[d[i]]--;
            ok = true;
        }
        else {
            ok = false;
        }
    }


    for (auto it : mp) {
        if (it.second > 0) ok = false;
    }

    if (ok) cout << "YES\n";
    else cout << "NO\n";

/*

4
3 1 7 8
2 2 7 10
5
10 3 2 2 1


3
1 2 1
1 3 2
4
1 3 1 2

*/


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