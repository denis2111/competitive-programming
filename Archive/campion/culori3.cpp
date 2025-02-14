#include <bits/stdc++.h>
using namespace std;

int n, bst_color;
string color, name, encoded_bst;
vector<string> bst_names;

int decode(string color) {
    int ans = 0;
    for (int digit : color) {
        if (digit == '#')
            continue;

        ans *= 16;
        if (digit >= 'A') {
            ans += (digit - 'A' + 10);
        } else {
            ans += (digit - '0');
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    freopen("culori3.in", "r", stdin);
    freopen("culori3.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> name >> color;
        int current_val = decode(color);

        if (current_val > bst_color) {
            bst_color = current_val;
            encoded_bst = color;
            bst_names.clear();
        }

        if (current_val == bst_color) {
            bst_names.push_back(name);
        }
    }

    cout << encoded_bst << '\n';

    sort(bst_names.begin(), bst_names.end());

    for (auto name : bst_names) {
        cout << name << '\n';
    }

    return 0;
}