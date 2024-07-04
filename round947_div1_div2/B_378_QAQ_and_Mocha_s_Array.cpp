#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve () {
    ll n; cin >> n;
    vector <ll> v(n);
    for (auto &it : v) cin >> it;
    sort(v.begin(), v.end());
    ll neven = 0;
    ll nodd = 0;

    vector <ll> evens;
    vector <ll> odds;

    for (auto it : v) {
        if (it & 1) {
            nodd++;
            odds.emplace_back (it);
        }
        else {
            neven++; 
            evens.emplace_back(it);
        }
    }

    // El menor de impares es fija
    vector <ll> rejected;
    // ok
    for (int i = 0; i < nodd; i++) {
        if (odds[i] % odds[0] != 0) {
            rejected.emplace_back(odds[i]);
        }
    }


    for (int i = 0; i < rejected.size(); i++) {
        if (rejected[i] % rejected[0] != 0) {
            cout << "No\n";
            return;
        }
    }


    // o bien es el menor par, o es el menor impar, o es un impar random
    // 14  = 2 7
    // 1 4 7 14 16 
    // 3 7 14 21 28
    for (int i = 0; i < neven; i++) {
        if (rejected.size() > 0 and nodd > 0) {
            if ((evens[i] % odds[0] != 0) and (evens[i] % rejected[0] != 0)) {
                cout << "No\n";
                return;
            }
        }   
        else {
            if (evens[i] % evens[0] != 0) {
                if ((nodd > 0) and (evens[i] % odds[0] != 0)) {
                    cout << "No\n"; return;
                }
            }
        }
    }

   
    cout << "Yes\n";        
    
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