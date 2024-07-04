#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve () {
    ll m, x; cin >> m >> x;
    ll ans = 0;
    ll dp[60][10006]{};
    ll peso[100]{}, valor[100]{};
    for (ll i = 0; i < m; i++) {
        cin >> peso[i] >> valor[i];
    }
   
    for (ll i = 1; i < m; i++) {
        dp[i][0] =  0;
        for (ll j = 1; j <= x*(i-1); j++) { 
            // No escojes
            dp[i][j] = dp[i - 1][j];
            
            if (j > peso[i]) {
                dp[i][j] = max (dp[i][j], dp[i - 1][j - peso[i]] + valor[i]);
            }
        }
        for (ll j = x*(i-1) + 1; j < 10004; j++) {
            dp[i][j] = dp[i][j - 1];
        }
    }
    cout << dp[m - 1][x*(m-1)] << '\n';
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