/*
    Link: https://kilonova.ro/contests/1485/problems/3654
    Source: FIICode 2025 Qualifying Round

    Solution: ...

    Complexity: O(n*log(n))

    Time to solve: 18 min
    Date: 23 Mar 2025
*/

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define NMAX 300005
#define ll long long

int n, v[NMAX];

long long _pow(long long a, long long b){
    long long ans = 1;
    for (; b; b >>= 1){
      if (b % 2) ans = ans * a % MOD;
      a = a * a % MOD;
      }
    return ans;
  }

int main() {
    ios::sync_with_stdio(false);
    cin >>  n;
    ll r = 0;
    for (int i=1;i<=n;i++) {
        cin >> v[i];
        r += v[i];
    }

    sort(v+1,v+n+1);
    ll l = 0, sum = 0;
    for (int i=1;i<=n;i++) {
        r -= v[i];
        sum = (sum + (r - 1LL * (n - i) * v[i])) % MOD;
        sum = (sum + (1LL * (i-1) * v[i] - l)) % MOD;
        l += v[i];
    }

    sum = sum * _pow(n-1, MOD - 2) % MOD;

    cout << sum << '\n';

    return 0;
}