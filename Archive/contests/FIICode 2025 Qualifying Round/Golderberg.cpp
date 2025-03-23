/*
    Link: https://kilonova.ro/contests/1485/problems/3652
    Source: FIICode 2025 Qualifying Round

    Solution: ...

    Complexity: O(n*k)

    Time to solve: 15 min
    Date: 23 Mar 2025
*/

#include <bits/stdc++.h>
using namespace std;

#define NMAX 300005
#define ll long long

int n, v[NMAX], c[NMAX], t[NMAX], k;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i=1;i<=n;i++) {
        cin >> v[i];
    }

    sort(v+1,v+n+1);

    cin >> k;
    for (int i=1;i<=k;i++) {
        cin >> t[i];
    }
    ll ans = 0;
    for (int i=1;i<=k;i++) {
        cin >> c[i];
        int st = 1, mx = 0;
        for (int j=1;j<=n;j++) {
            while (st < j && v[j] - v[st] > t[i]) st++;
            mx = max(mx, c[i] - abs(v[j] - v[st] - t[i]));
            if (st > 1) {
                mx = max(mx, c[i] - abs(v[j] - v[st-1] - t[i]));
            }
        }
        ans += mx;
    }

    cout << ans << '\n';


    return 0;
}