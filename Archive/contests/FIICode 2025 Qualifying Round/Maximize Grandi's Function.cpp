/*
    Link: https://kilonova.ro/contests/1485/problems/3657
    Source: FIICode 2025 Qualifying Round

    Solution: ...

    Complexity: O(n*log(n))

    Time to solve: 5 min
    Date: 23 Mar 2025
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define NMAX 100005

int n, v[NMAX];
deque<int> d;

int main() {
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i=1;i<=n;i++) {
        cin >> v[i];
    }

    sort(v + 1, v + n + 1);
    for (int i=1;i<=n;i++) {
        d.push_back(v[i]);
    }

    ll ans = 0;
    for (int i=1;i<=n;i++) {
        if (i % 2 == 1) {
            ans += d.back();
            d.pop_back();
        } else {
            ans -= d.front();
            d.pop_front();
        }
    }
    cout << ans << '\n';



    return 0;
}