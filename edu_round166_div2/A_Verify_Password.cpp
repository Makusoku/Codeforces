#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve () {
    ll n; cin >> n;
    string s;
    cin >> s;
    bool ok = true;
    for (ll i = 0; i < n; i++) {
        if (!(s[i] >= '0' and s[i] <= '9') and !(s[i] >= 'a' and s[i] <= 'z')) ok = false;
    }

    if (!ok) {
        cout << "NO\n";
        return;
    }

    ok = true;

    for (ll i = 0; i < n - 1; i++) {
        if ((s[i + 1] >= '0' and s[i + 1] <= '9') and (s[i] >= 'a' and s[i] <= 'z')) ok = false;
    }

    if (!ok) {
        cout << "NO\n";
        return;
    }

    ok = true;

    string num = "", lett = "";
    for (ll i = 0; i < n; i++) {
        if (s[i] >= '0' and s[i] <= '9') num += s[i];
        if (s[i] >= 'a' and s[i] <= 'z') lett += s[i];
    }

    if (!(is_sorted(num.begin(), num.end()))) ok = false;
    if (!(is_sorted(lett.begin(), lett.end()))) ok = false;

    if (!ok) {
        cout << "NO\n";
    }
    else {cout << "YES\n";}



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