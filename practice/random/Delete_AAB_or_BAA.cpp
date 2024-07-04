#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve () {
    stack <pair<ll,ll>> s;
    int n, arr[100];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    s.emplace (make_pair (arr[0], 0));

    for (int i = 0; i < n; i++) {
        if (i == 0) cout << "0 ";
        else {
            if (s.empty() || s.top().first > arr[i]) {
                cout << "0 ";
                s.emplace (make_pair (arr[i], 0));
            }
            else {
                int ans = 0;
                while (!s.empty() && s.top().first <= arr[i]) {
                    ans += s.top().second + 1;
                    s.pop();
                }
                s.emplace (make_pair (arr[i], ans));
                cout << ans << " ";
            }
        }
    }
 
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll _ = 1;
    //cin >> _;
    while (_--)
        solve ();
    return 0;
}