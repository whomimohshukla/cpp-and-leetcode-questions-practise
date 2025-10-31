#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Recursive function with memoization
int solveUsingMem(int n, vector<int> &dp) {

    // base cases
    if (n == 0 || n == 1) {
        return n;
    }

    // if already calculated, return from dp
    if (dp[n] != -1) {
        return dp[n];
    }

    // store and return computed result
    dp[n] = solveUsingMem(n - 1, dp) + solveUsingMem(n - 2, dp);
    return dp[n];
}

// main Fibonacci function
int fibonacci(int n) {
    vector<int> dp(n + 1, -1); // dp array initialized with -1
    return solveUsingMem(n, dp);
}

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;

    int ans = fibonacci(n);
    cout << "Fibonacci(" << n << ") = " << ans << endl;

    return 0;
}
