#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve () {
    ll n, m; cin >> n >> m;
    if (n < m) {
        cout << "No\n";
        return;
    }
    if ((n - m) % 2 == 0) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
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