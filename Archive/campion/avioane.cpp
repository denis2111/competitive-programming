/*
    Link: http://campion.edu.ro/arhiva/index.php?page=problem&action=view&id=1303
    Source: Finala .campion 2011

    Solution:
    Backtracking

    Complexity: O(4^((n-5)*(n-5)))
        However it is much smaller because many combinations are impossible.
*/
#include <bits/stdc++.h>
using namespace std;

int n, v[10];
// Use bitmask to store a plane as 5 integers.
// We set only the plane with face upward. The other three are computed at run
// time.
int plane_config[4][5] = {
    {1 << 2 /*00100*/, (1 << 5) - 1 /*11111*/, 1 << 2 /*00100*/,
     (1 << 1) + (1 << 2) + (1 << 3) /*01110*/, (1 << 2) /*00100*/},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}};

// Rotate 90 degrees left
void rotate_plane(int plane1[], int plane2[]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (plane1[j] & 1 << (4 - i)) plane2[i] ^= 1 << j;
        }
    }
}

struct result {
    int x, y, rot;
};

vector<result> ans, crt_ans;
int final_ans[10][10];

bool can_place(int plane[], int x, int y) {
    for (int i = 0; i < 5; i++) {
        if ((plane[i] << y) & v[x + i]) {
            return false;
        }
    }
    return true;
}

void place(int plane[], int x, int y) {
    for (int i = 0; i < 5; i++) v[x + i] ^= plane[i] << y;
}

void bkt(int x, int y) {
    if (x == n - 4) {
        if (crt_ans.size() > ans.size()) {
            ans = crt_ans;
        }
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (!can_place(plane_config[i], x, y)) continue;

        place(plane_config[i], x, y);
        crt_ans.push_back({x, y, i});

        if (y < n - 5)
            bkt(x, y + 1);
        else
            bkt(x + 1, 0);

        // running place again will remove the plane
        place(plane_config[i], x, y);
        crt_ans.pop_back();
    }

    if (y < n - 5)
        bkt(x, y + 1);
    else
        bkt(x + 1, 0);
}

int main() {
    ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("avioane.in", "r", stdin);
    freopen("avioane.out", "w", stdout);
#endif

    rotate_plane(plane_config[0], plane_config[1]);
    rotate_plane(plane_config[1], plane_config[2]);
    rotate_plane(plane_config[2], plane_config[3]);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> final_ans[i][j];
            if (final_ans[i][j] == -2) {
                v[i] ^= (1 << j);
            }
        }
    }

    bkt(0, 0);

    int id = 0;
    for (vector<result>::iterator it = ans.begin(); it != ans.end(); ++it) {
        ++id;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (plane_config[it->rot][i] & (1 << j))
                    final_ans[it->x + i][it->y + j] = id;
            }
        }
    }

    cout << ans.size() << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << final_ans[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}