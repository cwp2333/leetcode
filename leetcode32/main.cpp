/*
 * name:Mr.Cai
 * num:1
 * 最长有效括号
 * 算法思路：动态规划
 * */

#include <stack>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {

public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.length(), 0);
        int num = s.length();
        int maxV = 0;
        for (int i = 1; i < num; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = 2;
                    if (i - 2 > 0) {
                        dp[i] += dp[i - 2];
                    }
                } else if (dp[i - 1] > 0) {
                    if ((i - dp[i - 1] - 1) >= 0 && s[i - dp[i - 1] - 1] == '(') {
                        dp[i] = dp[i - 1] + 2;
                        if ((i - dp[i - 1] - 2) >= 0) {
                            dp[i] += dp[i - dp[i - 1] - 2];
                        }
                    }
                }
            }
            maxV = max(maxV, dp[i]);
        }
        return maxV;
    }
};
int main()
{
    Solution s1;
    string s = "(()";
    cout<< s1.longestValidParentheses(s)<<endl;
    return  0;
}