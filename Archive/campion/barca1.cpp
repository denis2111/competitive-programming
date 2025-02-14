/*
    Link: http://campion.edu.ro/arhiva/index.php?page=problem&action=view&id=539
    Source: Finala .campion 2005

    Solution:
    Use a heap that simulates the boat. On top of the heap is the sits the heaviest dwarf.

    Complexity: O((n + m)*log(n + m))

*/

#include <bits/stdc++.h>
using namespace std;

#define NMAX 200000

int n, g, m, total_w, v[10], res[NMAX];
int crt = 1;

class Compare {
public:
    bool operator()(pair<int, int> below, pair<int, int> above)
    {
        if (below.first < above.first) {
            return true;
        }
        else if (below.first == above.first && below.second > above.second) {
            return true;
        }

        return false;
    }
};

priority_queue<pair<int, int>, std::vector<pair<int, int> >, Compare > boat;


void remove() {
    while (total_w > g) {
        pair<int, int> el = boat.top();
        total_w -= el.first;
        res[el.second] = crt++;
        boat.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
        freopen("barca1.in", "r", stdin);
        freopen("barca1.out", "w", stdout);
    #endif

    cin >> n >> g >> m;

    for (int i = 0; i < 10; i++) {
        cin >> v[i];
    }
    
    for (int i = 1; i < n; i++) {
        int w;
        cin >> w;
        boat.push(make_pair(w, i));
        total_w += w;
    }

    for (int i = n; i <= n + m; i++) {
        remove();
        int w;
        cin >> w;
        boat.push(make_pair(w, i));
        total_w += w;
    }
    remove();

    for (int i = 0; i < 10; i++) {
        cout << res[v[i]] << '\n';
    }

    return 0;
}