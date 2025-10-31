#include <iostream>
#include <vector>
using namespace std;

//
// 🧩 1️⃣ Recursive + Memoization (Top-Down)
//

// Helper function: solves using recursion and memoization
int solveUsingMem(int n, vector<int> &dp) {

    // 🟢 Base cases
    if (n == 0 || n == 1) {
        return n; // fib(0)=0, fib(1)=1
    }

    // 🟡 Step 1: If already calculated, return from dp
    if (dp[n] != -1) {
        return dp[n];
    }

    // 🟠 Step 2: Otherwise, calculate and store result
    dp[n] = solveUsingMem(n - 1, dp) + solveUsingMem(n - 2, dp);

    // Return stored result
    return dp[n];
}

// Wrapper function for memoization
int fibonacciMemoization(int n) {
    // Create a dp array initialized with -1
    vector<int> dp(n + 1, -1);

    // Call helper function
    return solveUsingMem(n, dp);
}

//
// 🧩 2️⃣ Tabulation (Bottom-Up DP)
//
int fibonacciTabulation(int n) {
    // 🔹 Step 1: Create a dp array of size n+1
    vector<int> dp(n + 1, 0);

    // 🔹 Step 2: Initialize base cases
    dp[0] = 0;
    if (n >= 1)
        dp[1] = 1;

    // 🔹 Step 3: Fill dp table iteratively
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    // 🔹 Step 4: The nth Fibonacci number is stored in dp[n]
    return dp[n];
}

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;

    // Using Memoization
    int ans1 = fibonacciMemoization(n);
    cout << "Using Memoization: Fibonacci(" << n << ") = " << ans1 << endl;

    // Using Tabulation
    int ans2 = fibonacciTabulation(n);
    cout << "Using Tabulation: Fibonacci(" << n << ") = " << ans2 << endl;

    return 0;
}
