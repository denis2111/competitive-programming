/*
    Link: https://kilonova.ro/contests/1485/problems/3658
    Source: FIICode 2025 Qualifying Round

    Solution: Keep one segment tree for each bit.

    Complexity: O(n * log(MAX_VAL) * log(n))

    Time to solve: 30 min
    Date: 23 Mar 2025
*/

#include <bits/stdc++.h>
using namespace std;

#define NMAX 100005
#define ll long long

int n, v[NMAX], k;
ll AINT[31][NMAX * 4];

void _set(ll aint[], int l, int r, int x, int st, int dr, int nod) {
    if (l <= st && dr <= r) {
        aint[nod] = x;
        return;
    }

    if (aint[nod] == 0) {
        aint[nod * 2] = aint[nod * 2 + 1] = 0;
    }

    int mid = (st + dr) / 2;
    if (l <= mid) {
        _set(aint, l, r, x, st, mid, nod * 2);
    } if (r > mid) {
        _set(aint, l, r, x, mid + 1, dr, nod * 2 + 1);
    }

    aint[nod] = aint[nod * 2] + aint[nod * 2 + 1];
}

ll sum(ll aint[], int l, int r, int st, int dr, int nod) {
    if (l <= st && dr <= r) {
        return aint[nod];
    }

    if (aint[nod] == 0) {
        return 0;
    }

    int mid = (st + dr) / 2;
    ll ans = 0;
    if (l <= mid) {
        ans += sum(aint, l, r, st, mid, nod * 2);
    } if (r > mid) {
        ans += sum(aint, l, r, mid + 1, dr, nod * 2 + 1);
    }
    return ans;
}

void replace(int p, int x) {
    for (int k=0;k<=30;k++) {
        _set(AINT[k], p, p, x & (1<<k), 1, n, 1);
    }
}

void and_op(int l, int r, int x) {
    for (int k=0;k<=30;k++) {
        if (!(x & (1<<k)))
            _set(AINT[k], l, r, 0, 1, n, 1);
    }
}

ll sum_all(int l, int r) {
    ll ans = 0;
    for (int k=0;k<=30;k++) {
        ans += sum(AINT[k], l, r, 1, n, 1);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i=1;i<=n;i++) {
        cin >> v[i];
        for (int k=0;k<=30;k++) {
            if (v[i] & (1<<k)) {
                _set(AINT[k], i, i, 1<<k, 1, n, 1);
            }
        }
    }

    cin >> k;
    for (int i=1;i<=k;i++) {
        int t, p, x, l, r;
        cin >> t;
        if (t == 1) {
            cin >> p >> x;
            replace(p, x);
        } else if (t == 2) {
            cin >> l >> r >> x;
            and_op(l, r, x);
        } else if (t == 3) {
            cin >> l >> r;
            cout << sum_all(l, r) << '\n';
        }
    }
    return 0;
}