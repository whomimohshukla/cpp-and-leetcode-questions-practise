// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// class Solution {
// public:
//     // Recursive function to calculate maximum money robbed
//     int solveUsingRecursion(vector<int>& nums, int index) {
//         // base case
//         if (index >= nums.size()) {
//             return 0;
//         }

//         // recursive calls
//         int include = nums[index] + solveUsingRecursion(nums, index + 2);
//         int exclude = 0 + solveUsingRecursion(nums, index + 1);

//         int ans = max(include, exclude);
//         return ans;
//     }

//     int rob(vector<int>& nums) {
//         int index = 0;
//         int ans = solveUsingRecursion(nums, index);
//         return ans;
//     }
// };

// int main() {
//     Solution s;

//     // Example input
//     vector<int> nums = {2, 7, 9, 3, 1};

//     cout << "Maximum amount that can be robbed: " << s.rob(nums) << endl;

//     return 0;
// }



//using dp 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int solveUsingDP(vector<int>& nums, int index, vector<int>& dp) {
        if (index >= nums.size()) {
            return 0;
        }

        if (dp[index] != -1) {
            return dp[index];
        }

        int include = nums[index] + solveUsingDP(nums, index + 2, dp);
        int exclude = 0 + solveUsingDP(nums, index + 1, dp);

        dp[index] = max(include, exclude);
        return dp[index];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        int ans = solveUsingDP(nums, 0, dp);
        return ans;
    }
};

int main() {
    Solution s;

    // Example input
    vector<int> nums = {2, 7, 9, 3, 1};

    cout << "Maximum amount that can be robbed: " << s.rob(nums) << endl;

    return 0;
}
