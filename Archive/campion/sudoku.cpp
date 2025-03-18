/*
    Link: http://campion.edu.ro/arhiva/index.php?page=problem&action=view&id=467
    Source:  .campion 2005

    Solution:

    Keep a visited vector for each line, each column and each area of 3 by 3. 
    This helps us to check if we can write a value in a cell in O(1). 
    Using backtracking algorithm try all possibilities to fill the matrix.

    Complexity: 
        An upperbound of the complexity is: 9! * 8! * 7! * ... * 2! however
        in practice it is much smaller because the solution is unique.
    
    TO DO: Compute a better upperbound for complexity. The above doesn't take the 3 by 3 
    areas into account. 
*/

#include <bits/stdc++.h>
using namespace std;

int l[10][10], c[10][10], area[10][10];
string s[9];

void bkt(int i, int j) {
    if (i == 9 && j == 0) {
        for (int i = 0; i < 9; i++) {
            cout << s[i] << '\n';
        }
        exit(0);
    }

    if (s[i][j] != '0') {
        if (j == 8)
            bkt(i + 1, 0);
        else
            bkt(i, j + 1);
        return;
    }

    for (int k = 1; k < 10; k++) {
        if (l[i][k] || c[j][k] || area[i / 3 * 3 + j / 3][k])
            continue;
        s[i][j] = k + '0';
        l[i][k] = c[j][k] = area[i / 3 * 3 + j / 3][k] = 1;

        if (j == 8)
            bkt(i + 1, 0);
        else
            bkt(i, j + 1);

        l[i][k] = c[j][k] = area[i / 3 * 3 + j / 3][k] = 0;
        s[i][j] = '0';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
        freopen("sudoku.in", "r", stdin);
        freopen("sudoku.out", "w", stdout);
    #endif

    for (int i = 0; i < 9; i++) {
        cin >> s[i];
        for (int j = 0; j < 9; j++) {
            l[i][s[i][j] - '0'] = 1;
            c[j][s[i][j] - '0'] = 1;
            area[i / 3 * 3 + j / 3][s[i][j] - '0'] = 1;
        }
    }

    bkt(0, 0);

    return 0;
}