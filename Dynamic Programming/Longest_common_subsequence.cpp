
//link: "https://leetcode.com/problems/longest-common-subsequence/"


class Solution {
public:
    int solve(string &t1, string &t2, int i , int j,  vector<vector<int>>& dp) {
        if(i == t1.size() || j == t2.size()) return 0;
        if(dp[i][j] !=-1 ) return dp[i][j];
        //character match
        if(t1[i] == t2[j]){
            return dp[i][j]= 1 + solve(t1, t2, i+1, j+1, dp);
        }
        //character doesn't match

        int option1 = solve(t1, t2, i+1, j, dp);
        int option2 = solve(t1, t2, i, j+1, dp);
        return dp[i][j] =  max(option1, option2);
    }
    int longestCommonSubsequence(string t1, string t2) {
        int n1 = t1.size();
        int n2 = t2.size();
        vector<vector<int>> dp(n1, vector<int> (n2, -1));
        return solve(t1, t2, 0, 0, dp);
    }
};
