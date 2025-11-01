#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 🧩 Simple Recursion (Exponential time)
    int solveUsingRecu(vector<int>& coins, int amount) {
        // base cases
        if (amount == 0)
            return 0;
        if (amount < 0)
            return INT_MAX;

        int mini = INT_MAX;

        for (int i = 0; i < coins.size(); i++) {
            int recursionKaAns = solveUsingRecu(coins, amount - coins[i]);

            if (recursionKaAns != INT_MAX) {
                int ans = 1 + recursionKaAns;
                mini = min(mini, ans);
            }
        }

        return mini;
    }

    // 🧠 Recursion + Memoization (Top-Down DP)
    int usingMemo(vector<int>& coins, int amount, vector<int>& dp) {
        // base cases
        if (amount == 0)
            return 0;
        if (amount < 0)
            return INT_MAX;

        if (dp[amount] != -1) {
            return dp[amount];
        }

        int mini = INT_MAX;

        for (int i = 0; i < coins.size(); i++) {
            int recursionKaAns = usingMemo(coins, amount - coins[i], dp);

            if (recursionKaAns != INT_MAX) {
                int ans = 1 + recursionKaAns;
                mini = min(mini, ans);
            }
        }

        // store result for reuse
        dp[amount] = mini;

        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);

        int ans = usingMemo(coins, amount, dp);

        return (ans == INT_MAX) ? -1 : ans;
    }
};

int main() {
    Solution s;

    vector<int> coins = {1, 2, 5};
    int amount = 11;

    int result = s.coinChange(coins, amount);

    if (result == -1)
        cout << "It's not possible to make amount " << amount << " with the given coins." << endl;
    else
        cout << "Minimum coins required to make amount " << amount << ": " << result << endl;

    return 0;
}
