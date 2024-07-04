#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve () {
    ll x; cin >> x;
    vector <ll> bin;
    ll numBin = x;
    while (numBin > 0) {
        bin.push_back(numBin % 2);
        numBin /= 2;
    }

    for (ll i = 0; i < bin.size() - 1; i++) {
        if (bin[i] != 0 and bin[i + 1] != 0) {
            bin[i] = -1;
            bin[i + 1]++;
            if (bin[i + 1] == 2) {
                for (ll j = i + 1; j < bin.size(); j++) {
                    if (bin[j] == 2) {
                        bin[j] = 0;
                        if (j + 1 == bin.size()) bin.emplace_back(1);
                        else bin[j + 1]++;
                    }    
                }
            }
        }
    }
    cout << bin.size() << '\n';
    for (auto it : bin) cout << it << " "; cout << '\n';

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