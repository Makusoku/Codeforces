#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> decimalToBinary(ll n) {
    vector<ll> binaryDigits;
    
    // Manejar caso especial para el número 0
    if (n == 0) {
        binaryDigits.push_back(0);
        return binaryDigits;
    }
    
    // Convertir decimal a binario
    while (n > 0) {
        ll bit = n % 2;
        binaryDigits.insert(binaryDigits.begin(), bit); // Insertar al principio del vector
        n /= 2;
    }
    
    reverse (binaryDigits.begin(), binaryDigits.end());
    return binaryDigits;
}

void solve () {
    ll x, y;
    cin >> x >> y;
    vector <ll> binX = decimalToBinary(x);
    vector <ll> binY = decimalToBinary(y);  

    if (binX.size() < binY.size()) {
        ll esp = binY.size() - binX.size();
        for (ll i = 0; i < esp; i++) binX.emplace_back(0);
    }
    else {
        ll esp = binX.size() - binY.size();
        for (ll i = 0; i < esp; i++) binY.emplace_back(0);
        
    }

    ll ans =  0;

    for (ll i = 0; i < binX.size() and i < binY.size(); i++) {
        if (binX[i] != binY[i]) break;
        ans++;
    }
    cout << (1LL << ans) << '\n';
    
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