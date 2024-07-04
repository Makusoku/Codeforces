#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve () {
    ll n, k; cin >> n >> k;

    if (k & 1) cout << "NO\n";
    else {
        ll mx = 0;
        if (n & 1) mx = (n - 1) * ((n - 1) / 2 + 1);
        else mx = n * n / 2;

        if (k > mx) cout << "NO\n";
        else {
            cout << "YES\n";
            vector <ll> v (n + 1);
            vector <ll> aux;    
            for (ll i = 0; i <= n; i++) v[i] = i;
 
            for (ll i = 1; i <= (n + 1) / 2; i++) 
                aux.emplace_back (2 * (v[n - i + 1] - i));
            sort (aux.begin(), aux.end());

            for (auto it : aux) cout << it << " "; cout << endl;
            
            int ind;
            
            while (k > 0) {
                auto it = lower_bound (aux.begin(), aux.end(), k);
                if (it == aux.end()) ind = aux.size() - 1;
                else ind = distance (aux.begin(), it);
                swap (v[ind], v[k - ind - 1]);
                cout << k << " " << ind << " " << aux[ind] << endl;
                k -= aux[ind];
            }

            for (int i = 1; i <= n; i++) cout << v[i] << " \n"[i == n];
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