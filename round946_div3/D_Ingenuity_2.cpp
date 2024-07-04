#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve () {
    ll n; cin >> n;
    string s; cin >> s;
    map <char, ll> m;
    for (auto it : s) m[it]++;

    vector <char> v1, v2;
    
    if (m['N'] == m['S']) {
        
        if (m['W'] == m['E']) {
            if (m['W'] & 1) {cout << "NO\n"; return;}

            char ans[n];
            
            ll w = m['W'];
            ll e = m['E'];
            ll no = m['N'];
            ll so = m['S'];

            for (ll i = 0; i < n; i++) {
                if (s[i] == 'W') {
                    if (w > m['W'] / 2) ans[i] = 'R';
                    else ans[i] = 'H';
                    w--;
                }
                if (s[i] == 'E') {
                    if (e > m['E'] / 2) ans[i] = 'R';
                    else ans[i] = 'H';
                    e--;
                }
                if (s[i] == 'N') {
                    if (no > m['N'] / 2) ans[i] = 'R';
                    else ans[i] = 'H';
                    no--;
                }
                if (s[i] == 'S') {
                    if (so > m['S'] / 2) ans[i] = 'R';
                    else ans[i] = 'H';
                    so--;
                }
            }
        
        }
        else if (m['W'] > m['E']) {
            if ((m['W'] + m['E']) & 1) {cout << "NO\n"; return;}


        }
        else {
            if ((m['W'] + m['E']) & 1) {cout << "NO\n"; return;}
        }



    }
    else if (m['N'] > m['S']) {
        if ((m['N'] + m['S']) & 1) {cout << "NO\n"; return;}

        if (m['W'] == m['E']) {
            if (m['W'] & 1) {cout << "NO\n"; return;}
        
        }
        else if (m['W'] > m['E']) {
            if ((m['W'] + m['E']) & 1) {cout << "NO\n"; return;}
        }
        else {
            if ((m['W'] + m['E']) & 1) {cout << "NO\n"; return;}
        }



    }
    else {
        if ((m['N'] + m['S']) & 1) {cout << "NO\n"; return;}

        if (m['W'] == m['E']) {
            if (m['W'] & 1) {cout << "NO\n"; return;}
        
        }
        else if (m['W'] > m['E']) {
            if ((m['W'] + m['E']) & 1) {cout << "NO\n"; return;}
        }
        else {
            if ((m['W'] + m['E']) & 1) {cout << "NO\n"; return;}
        }


    }
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll _ = 1;
    cin >> _;
    while (_--) {
        cout << _ << endl;
        solve ();
    }
    return 0;
}