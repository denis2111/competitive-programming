/*
    Link: http://campion.edu.ro/arhiva/index.php?page=problem&action=view&id=1696
    Source: OMI2017

    Solution:

    We iterate through each color is converted in base 10 using `hex_to_decimal` function.
    When we discover a brighter color we reset the list of names with brightest colors (brightest_names) 
    and update brightest_color value.
    If the current color is equal with the brightest color discovered until now we add the name to 
    brightest_names list.
    At the end sort alphabetically the brightest_names list.


    Complexity: O(n) + O(n*log(n))

    Complexity description: 
        n*log(n) -> we have to sort all the names
*/
#include <bits/stdc++.h>
using namespace std;

int n, brightest_color = -1;
string encoded_brightest_color;
vector<string> brightest_names;

// Converts a color form base 16(hex) to base 10.
int hex_to_decimal(string color) {
    int ans = 0;
    for (string::iterator digit = color.begin(); digit != color.end(); ++digit) {
        if (*digit == '#')
            continue;

        ans *= 16;
        if (*digit >= 'A') {
            ans += (*digit - 'A' + 10);
        } else {
            ans += (*digit - '0');
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("culori3.in", "r", stdin);
    freopen("culori3.out", "w", stdout);
    #endif

    cin >> n;

    for (int i = 1; i <= n; i++) {
        string color, name;
        cin >> name >> color;
        int current_color = hex_to_decimal(color);

        if (current_color > brightest_color) {
            brightest_color = current_color;
            encoded_brightest_color = color;
            brightest_names.clear();
        }

        if (current_color == brightest_color) {
            brightest_names.push_back(name);
        }
    }

    cout << encoded_brightest_color << '\n';

    sort(brightest_names.begin(), brightest_names.end());

    for (vector<string>::iterator name = brightest_names.begin(); name != brightest_names.end(); ++name) {
        cout << *name << '\n';
    }

    return 0;
}