#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve () {
    string s; cin >> s;
    ll n = s.size();
    if (s[n - 1] == '9' or s[0] != '1') {
        cout << "NO\n";
    }
    else {
        for (ll i = 1; i < n - 1; i++) {
            if (s[i] == '0') {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
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