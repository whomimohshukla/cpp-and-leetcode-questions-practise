#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 🧮 Tabulation (Bottom-Up DP)
    int usingTabulation(vector<int>& coins, int amount) {
        // Step 1: Create a DP array
        vector<int> dp(amount + 1, INT_MAX);

        // Step 2: Base case — 0 amount needs 0 coins
        dp[0] = 0;

        // Step 3: Fill the dp table iteratively
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
        }

        // Step 4: If no solution found, return -1
        return (dp[amount] == INT_MAX) ? -1 : dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        return usingTabulation(coins, amount);
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
