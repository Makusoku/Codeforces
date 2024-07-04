#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool check (vector <char> v, ll k, ll n) {
    
    // 1 0 1 0 0 1
    for (int i = 0; i < n; i += k) {
        for (ll j = i; j < k + i and j < n; j++) {
            if (j + 1 < k + i and v[j] != v[j + 1]) return false;
            if (v[j + k] == v[j]) return false;
        }
    }

    return true;
}

void solve () {
    ll n, k; cin >> n >> k;
    string s; cin >> s;
    vector <char> v;
    for (auto it : s) v.emplace_back(it);

    ll sob = 1;
    for (ll i = n - 1; i > 0; i--) {
        if (s[i] != s[i - 1]) break;
        sob++;
    }

    if (sob >= k) {
            cout << "a\n";
        
    }
    else {
        // Si necesitamos mas para completar
        ll nec = k - sob;
        ll dig = v[n - 1];  // Esto es lo que necesito
        ll ind = 0;
        bool ok = true;
        for (int i = 0; i < n and ok; i += k) {
            for (ll j = i; j < k + i and j < n; j++) {
                if (j + 1 < k + i and v[j] != v[j + 1]) {
                    ind = j;
                    ok = false;
                    break;
                }
                if (j == k + i - 1 and k + i - 1 < n and v[j] == v[j + 1]) {
                    ind = j;
                    ok = false;
                    break;
                }
            }
        }

        // Cambiarlo
        for (ll i = ind; i >= 0; i--) {
            v.emplace_back(v[i]);
        }
        
        // Verificamos
        vector <char> aux;
        for (ll i = ind + 1; i < v.size(); i++) {
            aux.emplace_back(v[i]);
        }

        if (check(aux, k, aux.size())) {
            cout << ind + 1 << '\n';
        }
        else {
            cout << "-1\n";
        }
    }
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