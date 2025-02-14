/*
    Link: http://campion.edu.ro/arhiva/index.php?page=problem&action=view&id=1305
    Source: Finala .campion 2011
    
    Solution:

    For each substring of length 2 * L + 1 we check if exact L elements are smaller than the element in the middle.
    To check this we use a Binary Indexed Tree.

    Complexity: O(n*log(VAL_MAX))
*/
#include <bits/stdc++.h>
using namespace std;
#define VAL_MAX 500005
#define NMAX 800004
#define OFFSET 500001

int s[VAL_MAX + OFFSET + 1], n, l, v[NMAX];

int sum(int pos) {
    int sum = 0;
    pos += OFFSET;
    for (int i = pos; i >= 1; i -= i & (-i)) {
        sum += s[i];
    }
    return sum;
}

void add(int pos, int val) {
    pos += OFFSET;
    for (int i=pos;i<=VAL_MAX + OFFSET; i += i & (-i)) {
        s[i] += val;
    }
}

int main(){
    ios::sync_with_stdio(false);
    freopen("echilibru1.in", "r", stdin);
    freopen("echilibru1.out", "w", stdout);

    cin >> n >> l;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    for (int i = 1; i <= 2 * l + 1; i++) {
        add(v[i], 1);
    }

    int ans = 0;
    for (int i = 2 * l + 1; i <= n; i++) {
        int mid = v[i - l];
        if (sum(mid - 1) == l) {
            ans++;
        }
        add(v[i - 2 * l], -1);
        if (i < n)
            add(v[i+1], 1);
    }

    cout << ans << '\n';
    
    return 0;
}