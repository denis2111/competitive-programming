/*
    Link: http://campion.edu.ro/arhiva/index.php?page=problem&action=view&id=450
    Source: .campion 2005

    Solution:

    It is a classical problem of finding largest empty rectangle. It is also
   known as largest rectangle under histogram. 

    Complexity: O(n * m)

    Time to solve: 20min
    Date: 20 Mar 2025
*/

#include <bits/stdc++.h>
using namespace std;
#define NMAX 105
#define pii pair<int, int>

int n, m, up[NMAX][NMAX], x, x2, y, y2, ans;
string mat[NMAX];

deque<pii> q;

void pop_q(deque<pii>& q, int i, int j) {
    pii crt = q.back();
    q.pop_back();
    int area = crt.first * (j - 1 - q.back().second);
    if ((area > ans) || (area == ans && x > i - crt.first + 1) ||
        (area == ans && x == i - crt.first + 1 && y > q.back().second + 1) ||
        (area == ans && x == i - crt.first + 1 && y == q.back().second + 1) &&
            x2 > i) {
        ans = area;
        x = i - crt.first + 1;
        y = q.back().second + 1;
        x2 = i;
        y2 = j - 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("submatrix.in", "r", stdin);
    freopen("submatrix.out", "w", stdout);
#endif

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> mat[i];
        for (int j = 1; j <= m; j++) {
            if (mat[i][j - 1] == '1') {
                up[i][j] = up[i - 1][j] + 1;
            } else {
                up[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        q.clear();
        q.push_back({-1, 0});
        for (int j = 1; j <= m; j++) {
            while (q.back().first >= up[i][j]) {
                pop_q(q, i, j);
            }
            q.push_back({up[i][j], j});
        }
        while (q.back().first >= 0) {
            pop_q(q, i, m + 1);
        }
    }

    cout << ans << '\n';
    cout << x << ' ' << y << ' ' << x2 << ' ' << y2 << '\n';

    return 0;
}