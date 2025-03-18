/*
    Link: http://campion.edu.ro/arhiva/index.php?page=problem&action=view&id=555
    Source: Lot IS 2008

    Solution: 

    A description of an algorithm that produce optimal solution is:
        1. Having stacks sorted increasing by the number of tokens
        2. Take second half of stacks and substract as much as possible
        such that the smallest stack will become 0. (*)
        3. Sort the stacks again and repeat the process.

    This algorithm has floor(log(n)) + 1 steps because at each step we halve the number of 
    stacks that have distinct values.

    (*) When we take the second half we consider all stacks that have the same number
    of tokens as having weight 1. It means if we sort the distinct number of tokens in a
    stack, all stacks that have a number of tokens in the second half will be taken at 
    step 2. (TO DO: does it matter to compres equal values?)

    TO DO: Find a proof that log(n) is optimal answer. 

    Complexity: O(n * log(n))
*/


#include <bits/stdc++.h>
using namespace std;

#define NMAX 30005

int n;
// v[i] store the indices of all stacks that have i tokens
vector<int> v[NMAX];

int main() {
    ios_base::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
        freopen("stive.in", "r", stdin);
        freopen("stive.out", "w", stdout);
    #endif

    cin >> n;

    for (int i = 1; i <= n; i++) {
        v[i].push_back(i);
    }

    cout << int(floor(log2(n)) + 1) << '\n';

    for (int i = n; i >= 1; i /= 2) {
        int mid = i / 2 + 1;
        // total choosen stacks
        int cnt = 0;
        for (int j = mid; j <= i; j++) {
            cnt += v[j].size();
            v[j - mid].insert(v[j - mid].end(), v[j].begin(), v[j].end());
        }
        cout << cnt << ' ';
        for (int j = mid; j <= i; j++) {
            for (vector<int>::iterator stack_index = v[j].begin(); stack_index != v[j].end(); ++stack_index) {
                cout << *stack_index << ' ';
            }
        }
        cout << mid << '\n';
    }

    return 0;
}