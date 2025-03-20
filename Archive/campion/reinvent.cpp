/*
    Link: http://campion.edu.ro/arhiva/index.php?page=problem&action=view&id=253
    Source: ONI 2009 (grade 11-12)

    Solution: Start a BFS from all x points at once. Store the current distance traveled and stop when a house
   is visited from two starting points.

    Complexity: O(n + m)

    Time to solve:
        * 12 min (for first submission)
        * 17 min (full solve)
    Date: 20 Mar 2025
*/

#include <bits/stdc++.h>
using namespace std;

#define NMAX 100005
#define pii pair<int, int>

int n, m, x;

pii viz[NMAX];

vector<int> v[NMAX];
queue<int> q;

int main() {
    ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("reinvent.in", "r", stdin);
    freopen("reinvent.out", "w", stdout);
#endif

    cin >> n >> m >> x;

    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    for (int i = 1; i <= x; i++) {
        int c;
        cin >> c;
        q.push(c);
        viz[c] = {c, 0};
    }

    while (!q.empty()) {
        int nod = q.front();
        q.pop();

        for (vector<int>::iterator it = v[nod].begin(); it != v[nod].end(); ++it) {
            if (viz[*it].first == viz[nod].first) continue;
            if (viz[*it].first != 0) {
                cout << viz[nod].second + viz[*it].second + 1 << '\n';
                return 0;
            }
            viz[*it] = {viz[nod].first, viz[nod].second + 1};
            q.push(*it);
        }
    }

    return 0;
}