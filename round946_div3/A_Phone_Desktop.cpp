#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve () {
    ll a, b; cin >> a >> b;
    ll ans = 0;
    if (a == 0 and b == 0) cout << "0\n";
    else {
    ans += b / 2 + (b & 1);
    if (ans == 0) ans = 1;
    ll resto = 15 * ans - (b * 4);
    if (resto >= a) cout << ans << '\n';
    else {
        a -= resto;
        ans += a / 15 + (a % 15 != 0);
        cout << ans << '\n';
    }}
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