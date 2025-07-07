// recursion
class Solution {
  public:
    int solve(string& s1, string& s2, int i, int j, int count) {
        // Base case: if either string is exhausted
        if (i == 0 || j == 0) return count;

        // If characters match, extend the substring
        if (s1[i - 1] == s2[j - 1]) {
            count = solve(s1, s2, i - 1, j - 1, count + 1);
        }

        // Try all possibilities and keep max length
        int option1 = solve(s1, s2, i - 1, j, 0); // skip s1[i-1]
        int option2 = solve(s1, s2, i, j - 1, 0); // skip s2[j-1]

        return max({count, option1, option2});
    }

    int longestCommonSubstr(string& s1, string& s2) {
        int n = s1.length();
        int m = s2.length();

        return solve(s1, s2, n, m, 0);
    }
};

// Memoization + global behaviour

class Solution {
  public:
    int maxLen = 0;
    int solve(string& s1, string& s2, int i, int j, vector<vector<int>>& dp) {
        // Base case
        if (i == 0 || j == 0) return 0;

        // If already solved
        if (dp[i][j] != -1) return dp[i][j];

        // If characters match, increase substring length
        if (s1[i - 1] == s2[j - 1]) {
            dp[i][j] = 1 + solve(s1, s2, i - 1, j - 1, dp);
            maxLen = max(maxLen, dp[i][j]);
        } else {
            dp[i][j] = 0; // reset for non-contiguous match
        }

        // Explore other branches for full recursion
        solve(s1, s2, i - 1, j, dp);
        solve(s1, s2, i, j - 1, dp);

        return dp[i][j];
    }
    int longestCommonSubstr(string& s1, string& s2) {
        int n = s1.length();
        int m = s2.length();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        solve(s1, s2, n, m,dp);
        
        return maxLen;
    }
};

// 3D dp

// Tabulation

class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int n = s1.size();
        int m = s2.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    if(dp[i-1][j-1]!=0)
                        dp[i][j]=1+dp[i-1][j-1];
                    else
                        dp[i][j]=1;
                }
            }
        }
        
        int maxi = 0;
        for(int i = 1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(maxi < dp[i][j])
                    maxi = dp[i][j];
            }
        }
        
        return maxi;
    }
};
