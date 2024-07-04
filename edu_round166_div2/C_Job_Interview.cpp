#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve () {
    ll n, m; cin >> n >> m;
    vector <ll> p (n + m + 1); for (auto &it : p) cin >> it;
    vector <ll> t (n + m + 1); for (auto &it : t) cin >> it;

    ll sum = 0;
    ll sum_pro = 0, sum_tes = 0;
    ll n_p = 0, n_t = 0;
    multiset <pair<ll,ll>> program, tester;

    // Primer caso, el primero es eliminado
    for (ll i = 1; i < n + m + 1; i++) {

        // El tester esta lleno, o (n_programadores no esta vacio, y no es cero y sea mayor el skill)
        if ((n_p != n and n != 0 and p[i] > t[i]) or (n_t == m)) {
            n_p++;
            program.emplace(make_pair (p[i], i));
            sum_pro += p[i];
        }
        else {
            n_t++;
            tester.emplace(make_pair (t[i], i));
            sum_tes += t[i];
        }
    }
    sum = sum_pro + sum_tes;
    cout << sum << ' ';

    for (ll i = 1; i < n + m + 1; i++) {
        if (p[i] > t[i]) {
            if (n_p != 0) {
                // Verificamos el trabajo del anterior
                auto it = program.lower_bound(make_pair(p[i - 1], i - 1));
                // es programador
                if (it != program.end() and *it == make_pair (p[i - 1], i - 1)) {
                    sum_pro += p[i] - p[i - 1];                    
                }
                else {
                    // buscar el menor                         
                }

            }
            else {
                sum_tes += t[i] - t[i - 1];
            }
        }
        else {
            if (n_t != 0) {
                
            }
            else {
                sum_pro += p[i] - p[i - 1];                
            }
        }
        sum = sum_pro + sum_tes;
        cout << sum << ' ';
    }
    cout << endl;
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