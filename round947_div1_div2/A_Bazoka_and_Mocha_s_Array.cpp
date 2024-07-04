#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool check (queue <ll> &q) {
    vector <ll> v;
    for (int i = 0; i < q.size(); i++) {
        v.emplace_back(q.front());
        int a = q.front();
        q.pop();
        q.emplace(a);
    }
    return is_sorted(v.begin(), v.end());
}

void solve () {
    ll n; cin >> n;
    queue <ll> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.emplace(x);
    }

    for (int i = 0; i < 60; i++) {
        
        if (check(q) ) {
            cout << "YES\n";
            return;
        }
        int a = q.front();
        q.pop();
        q.emplace(a);
    }
    cout << "NO\n";
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