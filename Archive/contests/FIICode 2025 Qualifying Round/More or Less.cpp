/*
    Link: https://kilonova.ro/contests/1485/problems/3655
    Source: FIICode 2025 Qualifying Round

    Solution: v[i] stores how many permutations exists that respect a prefix of signs from l (or r
   depending on case) and last number of the prefix is ith smaller among the remaining numbers
   (number that were not choosen in the prefix).

    For the common prefix of l and r we have to respect the signs. After that we either follow l or
   r or we already are between l and r and is enough to multiple with all permutations of remaining
   numbers.

   First step after we past the common prefix will either make our sequence lower than r or
   greater than l. Then if we are equal to l and the next sign is '<' but we choose '>' now we are
   between l and r. Analogous if we are equal to r. At each step we can decide if we continue equal
   to l (or r) or choose the opposite sign. We can choose the opposite sign only in the case
   presented above.

    Complexity: O(t * n^2)

    Time to solve: 59 min
    Date: 23 Mar 2025
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007
#define NMAX 4005

int t, n, p[NMAX];
string l, r;
vector<int> v;

void add(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    if (a < 0) a += MOD;
}

void add_lower(vector<int> &v) {
    for (int i = 1; i + 1 < v.size(); i++) {
        add(v[i], v[i - 1]);
    }
    v.pop_back();
}

void add_greater(vector<int> &v) {
    int sum = v.back();
    for (int i = (int)v.size() - 2; i >= 0; i--) {
        int aux = v[i];
        v[i] = sum;
        add(sum, aux);
    }
    v.pop_back();
}

int get_sum(vector<int> &v) {
    int ans = 0;
    for (auto it : v) add(ans, it);
    return ans;
}

int solve(int i, vector<int> v, string &s, bool is_lower) {
    if (s[i] == '<')
        add_lower(v);
    else
        add_greater(v);

    int ans = 0;
    for (i++; i < s.size(); i++) {
        if (is_lower && s[i] == '<') {
            vector<int> clone = v;
            add_greater(clone);
            int sum = get_sum(clone);
            ans = (ans + 1LL * sum * p[clone.size() - 1]) % MOD;
        } else if (!is_lower && s[i] == '>') {
            vector<int> clone = v;
            add_lower(clone);
            int sum = get_sum(clone);
            ans = (ans + 1LL * sum * p[clone.size() - 1]) % MOD;
        }

        if (s[i] == '<')
            add_lower(v);
        else
            add_greater(v);
    }
    return ans + v[0];
}

int main() {
    ios::sync_with_stdio(false);

    p[0] = 1;
    p[1] = 1;
    for (int i = 2; i < NMAX; i++) {
        p[i] = 1LL * p[i - 1] * i % MOD;
    }

    cin >> t;
    while (t--) {
        cin >> n;
        v.clear();
        v.resize(n, 1);

        cin >> l >> r;

        int i = 0;
        while (i < l.size() && l[i] == r[i]) {
            if (l[i] == '<') {
                add_lower(v);
            } else {
                add_greater(v);
            }
            i++;
        }

        ll ans = 0;
        if (v.size() > 1) {
            ans += solve(i, v, l, true);
            ans += solve(i, v, r, false);
        } else {
            ans += v[0];
        }

        cout << ans % MOD << '\n';
    }
    return 0;
}