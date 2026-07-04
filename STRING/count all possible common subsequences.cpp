// Step 9: Complete recurrence

// If

// S[i-1]==T[j-1]
// dp[i][j]
// =
// dp[i-1][j]
// +
// dp[i][j-1]
// +
// 1;

// Else

// dp[i][j]
// =
// dp[i-1][j]
// +
// dp[i][j-1]
// -
// dp[i-1][j-1];
// Step 10: C++ Implementation
#include <bits/stdc++.h>
using namespace std;

int countCommonSubsequence(string s, string t)
{
    int n = s.size();
    int m = t.size();

    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + 1;
            }
            else
            {
                dp[i][j] = dp[i - 1][j]
                         + dp[i][j - 1]
                         - dp[i - 1][j - 1];
            }
        }
    }

    return dp[n][m];
}

int main()
{
    string s = "ajblqcpdz";
    string t = "aefcnbtdi";

    cout << countCommonSubsequence(s, t);
}
