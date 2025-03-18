#include <bits/stdc++.h>
using namespace std;

int n, v[10];
int plane_config[4][5] = {{1 << 2, (1 << 5) - 1, 1 << 2, (1 << 1) + (1 << 2) + (1 << 3), (1 << 2)}, {}, {}, {}};

int main() {
    ios_base::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
        freopen("avioane.in", "r", stdin);
        freopen("avioane.out", "w", stdout);
    #endif

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if (x == -2) {
                v[i] ^= (1 << j);
            }
        }
    }

    return 0;
}