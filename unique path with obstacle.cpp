//recursion
class Solution {
public:
    void fun(int m, int n, int& count,vector<vector<int>>&obstacleGrid) {
        if (m == 0 && n == 0) {
            count++;
            return;
        }
        if (m < 0 || n < 0)
            return;

        if(m-1>=0 && n>=0 && obstacleGrid[m-1][n]!=1)
            fun(m - 1, n, count,obstacleGrid);
        if(m>=0 && n-1>=0 && obstacleGrid[m][n-1]!=1)
            fun(m, n - 1, count,obstacleGrid);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int count = 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1]==1 || obstacleGrid[0][0]==1 ) return 0;
        fun(m-1,n-1,count,obstacleGrid);

        return count;
    }
};
//memoization
class Solution {
public:
    int fun(int m, int n,vector<vector<int>>&obstacleGrid,vector<vector<int>>&dp) {
        if (m == 0 && n == 0) return 1;
        if (m < 0 || n < 0) return 0;
        if(dp[m][n]!=-1) return dp[m][n];

        int up = 0;
        int right = 0;
        if(m-1>=0 && n>=0 && obstacleGrid[m-1][n]!=1)
            up = fun(m - 1, n,obstacleGrid,dp);
        if(m>=0 && n-1>=0 && obstacleGrid[m][n-1]!=1)
            right = fun(m, n - 1,obstacleGrid,dp);
        
        return dp[m][n]=up+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1]==1 || obstacleGrid[0][0]==1 ) return 0;
        vector<vector<int>>dp(m,vector<int>(n,-1));

        return fun(m-1,n-1,obstacleGrid,dp);
    }
};
//tabulation
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[m - 1][n - 1] == 1 || obstacleGrid[0][0] == 1)
            return 0;

        vector<vector<int>> dp(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(i==0 && j==0){
                    dp[i][j]=1;
                    continue;
                }
                int up = 0;
                int right = 0;
                if (i-1>= 0 && j >= 0 && obstacleGrid[i - 1][j] != 1)
                    up = dp[i-1][j];
                if (i >= 0 && j - 1 >= 0 && obstacleGrid[i][j - 1] != 1)
                    right = dp[i][j-1];

                dp[i][j]=up+right;
            }
        }
        return dp[m-1][n-1];
    }
};
// space optimization
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[m - 1][n - 1] == 1 || obstacleGrid[0][0] == 1)
            return 0;

        vector<int> prev(n, 0);

        for (int i = 0; i < m; i++) {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    curr[0] = 1;
                else {
                    int up = 0;
                    int right = 0;
                    if (i - 1 >= 0 && j >= 0 && obstacleGrid[i - 1][j] != 1)
                        up = prev[j];
                    if (i >= 0 && j - 1 >= 0 && obstacleGrid[i][j - 1] != 1)
                        right = curr[j - 1];
                    
                    curr[j] = up + right;
                }
            }

            prev = curr;
        }
        return prev[n - 1];
    }
};
