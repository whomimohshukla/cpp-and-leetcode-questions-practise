#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int solveUsingRecursion(string &a, string &b, int i, int j)
    {
        if (i >= a.length() || j >= b.length())
        {
            return 0;
        }

        if (a[i] == b[j])
        {
            return 1 + solveUsingRecursion(a, b, i + 1, j + 1);
        }
        else
        {
            return max(solveUsingRecursion(a, b, i, j + 1),
                       solveUsingRecursion(a, b, i + 1, j));
        }
    }

    int solveUsingMem(string &a, string &b, int i, int j,
                      vector<vector<int>> &dp)
    {
        if (i >= a.length() || j >= b.length())
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (a[i] == b[j])
        {
            dp[i][j] = 1 + solveUsingMem(a, b, i + 1, j + 1, dp);
        }
        else
        {
            dp[i][j] = max(solveUsingMem(a, b, i, j + 1, dp),
                           solveUsingMem(a, b, i + 1, j, dp));
        }

        return dp[i][j];
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        int i = 0, j = 0;
        vector<vector<int>> dp(text1.length() + 1,
                               vector<int>(text2.length() + 1, -1));

        return solveUsingMem(text1, text2, i, j, dp);
    }
};

int main()
{
    Solution s;
    string text1, text2;

    cout << "Enter first string: ";
    cin >> text1;

    cout << "Enter second string: ";
    cin >> text2;

    int result = s.longestCommonSubsequence(text1, text2);
    cout << "Longest Common Subsequence length: " << result << endl;

    return 0;
}
