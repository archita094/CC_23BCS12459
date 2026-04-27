#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3};
    int n = arr.size();

    int total = 1 << n;

    for (int mask = 0; mask < total; mask++) {
        vector<int> subset;

        for (int j = 0; j < n; j++) {
            if (mask & (1 << j)) {
                subset.push_back(arr[j]);
            }
        }
        cout << "{ ";
        for (int x : subset) cout << x << " ";
        cout << "}\n";
    }

    return 0;
}