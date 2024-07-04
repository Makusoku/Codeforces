#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve () {
    ll n, m; cin >> n >> m;
    vector <vector <ll>> a(n, vector <ll> (m));
    vector <vector <ll>> b(n, vector <ll> (m));

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cin >> b[i][j];
        }
    }


    vector <vector <ll>> a1(m);
    vector <vector <ll>> b1(m);

    for (ll i = 0; i < m; i++) {
        for (ll j = 0; j < n; j++) {
            a1[i].emplace_back(a[j][i]);
        }
    }

    for (ll i = 0; i < m; i++) {
        for (ll j = 0; j < n; j++) {
            b1[i].emplace_back(b[j][i]);
        }
    }
    
    // verificamos filas

    map <vector <ll> , ll> mRow;
    
    for (ll i = 0; i < n; i++) {
        sort (a[i].begin(), a[i].end());
        mRow[a[i]]++;
    }

    for (ll i = 0; i < n; i++) {
        sort (b[i].begin(), b[i].end());
        mRow[b[i]]++;
    }

    for (auto it :mRow) {
        if (it.second != 2) {
            cout << "NO\n";
            return;
        }
    }

    // verificamos columnas

    map <vector <ll> , ll> mCol;
    
    for (ll i = 0; i < m; i++) {
        sort (a1[i].begin(), a1[i].end());
        mCol[a1[i]]++;
    }

    for (ll i = 0; i < m; i++) {
        sort (b1[i].begin(), b1[i].end());
        mCol[b1[i]]++;
    }

    for (auto it :mCol) {
        //cout << it.second << " ";
        if (it.second != 2) {
            cout << "NO\n";
            return;
        }
    }


    cout << "YES\n";


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