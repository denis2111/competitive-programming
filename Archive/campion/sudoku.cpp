#include <bits/stdc++.h>
using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.first << ' ' << p.second << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}
#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

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