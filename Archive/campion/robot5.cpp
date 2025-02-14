/*
    Link: http://campion.edu.ro/arhiva/index.php?page=problem&action=view&id=1699
    Source: ONIGIM 2017
*/
#include <bits/stdc++.h>
using namespace std;

int c, n, h, m, s, t, v, r, broken_cnt;
vector<int> labels;

int to_seconds(int h, int m, int s) {
    return h * 60 * 60 + m * 60 + s;
}

void from_seconds(int &h, int &m, int &s, int seconds) {
    h = seconds / 3600;
    seconds -= h * 3600;
    m = seconds / 60;
    seconds -= m * 60;
    s = seconds;
}

int make_valid(int label) {
    vector<int> even, odd;
    while (label != 0) {
        int digit = label % 10;
        if (digit % 2 == 0) even.push_back(digit);
        else odd.push_back(digit);
        label /= 10;
    }

    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());

    if (even.empty()) {
        odd.erase(odd.begin());
        even.push_back(0);
    }

    if (odd.empty()) {
        even.pop_back();
        odd.push_back(9);
    }

    int res = 0;

    for (vector<int>::iterator digit = odd.begin(); digit != odd.end(); ++digit) {
        res = res * 10 + *digit;
    }

    for (vector<int>::reverse_iterator digit = even.rbegin(); digit != even.rend(); ++digit) {
        res = res * 10 + *digit;
    }

    return res;
}


int main() {
    ios_base::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
        freopen("robot5.in", "r", stdin);
        freopen("robot5.out", "w", stdout);
    #endif

    cin >> c >> n >> h >> m >> s;
    cin >> t >> v >> r;

    int seconds = to_seconds(h, m, s);
    
    for (int i = 1; i <= n; i++) {
        int label;
        cin >> label;
        int valid_label = make_valid(label);
        if (valid_label != label) {
            broken_cnt++;
        }
        labels.push_back(valid_label);
    }


    if (c == 1) {
        seconds += t * (n - 1) + v * n + r * broken_cnt;
        from_seconds(h, m, s, seconds);
        cout << h << ' ' << m << ' ' << s << '\n';
    } else {
        for (vector<int>::iterator label = labels.begin(); label != labels.end(); ++label) {
            cout << *label << '\n';
        }
    }




    return 0;
}