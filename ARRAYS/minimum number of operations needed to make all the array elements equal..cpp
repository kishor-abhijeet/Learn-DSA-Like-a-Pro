// problem statement: You are given an array `arr` of size `n` containing positive integers. Your goal is to make all the elements of the array equal by performing the minimum number of operations.

// In a single operation, you may choose any index `i` (where `1 ≤ i ≤ n`) and update the element at that index as follows:

// * `arr[i] = floor(arr[i] / 2)`

// You can perform this operation any number of times on any element of the array.

// Determine the minimum number of operations required to make all the elements in the array equal.

//code part:

#include <bits/stdc++.h>

using namespace std;

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector < int > arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int cnt = 0;
        sort(begin(arr), end(arr));
        if (arr[0] == arr[n - 1]) cout << 0 << endl;
        else {
            while (arr[n - 1] != 0) {
                if (arr[0] == arr[n - 1]) break;
                arr[n - 1] = arr[n - 1] / 2;
                sort(begin(arr), end(arr));
                cnt++;
            }
            cout << cnt << endl;
        }

    }

}
