/*
    Link: https://kilonova.ro/contests/1485/problems/3651
    Source: FIICode 2025 Qualifying Round

    Solution: ...

    Complexity: O(t*n)

    Time to solve: 20 min
    Date: 23 Mar 2025
*/

#include <bits/stdc++.h>
using namespace std;

#define NMAX 100005

int t, n, v[NMAX];
vector<int> cnt[3], ans;

void print1() {
    int t = 0;
    while (!cnt[1].empty() || !cnt[2].empty()) {
        if (t % 2 == 0) {
            cout << cnt[1].back() << ' ';
            cnt[1].pop_back();
        } else {
            cout << cnt[2].back() << ' ';
            cnt[2].pop_back();
        }
        t++;
    }
}

void print0() {
    for (auto it : cnt[0]) {
        cout << it << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> n;
        cnt[0].clear();
        cnt[1].clear();
        cnt[2].clear();
        for (int i=1;i<=n;i++) {
            cin >> v[i];
            cnt[v[i] % 3].push_back(v[i]);
        }

        if (cnt[0].size() > 0 && cnt[1].size() + cnt[2].size() == 0) {
            cout << "-1\n";
            continue;
        }
    
        if (int(cnt[1].size()) - cnt[2].size() == 2 || int(cnt[1].size()) - cnt[2].size() == 1) {
            cout << cnt[1].back() << ' ';
            cnt[1].pop_back();
            print1();
            print0();
        } else if (int(cnt[2].size()) - cnt[1].size() == 1 || int(cnt[2].size()) - cnt[1].size() == 2) {
            cout << cnt[2].back() << ' ';
            cnt[2].pop_back();
            if (!cnt[2].empty()) {
                cout << cnt[2].back() << ' ';
                cnt[2].pop_back();
                print1();
            }
            print0();
        } else {
            cout << "-1\n";
            continue;
        }
    
    }

    return 0;
}