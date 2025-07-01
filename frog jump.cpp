//BY RECURSION ONLY
//1.FROM BASE = 0;
class Solution {
public:
    int solve(int index, int n, vector<int>& height, int cost) {
        if (index == n - 1) return cost;

        int jumpOne = INT_MAX, jumpTwo = INT_MAX;

        // Jump to index + 1
        if (index + 1 < n)
            jumpOne = solve(index + 1, n, height, cost + abs(height[index] - height[index + 1]));

        // Jump to index + 2
        if (index + 2 < n)
            jumpTwo = solve(index + 2, n, height, cost + abs(height[index] - height[index + 2]));

        return min(jumpOne, jumpTwo);
    }

    int minCost(vector<int>& height) {
        int n = height.size();
        return solve(0, n, height, 0);
    }
};
//2.FROM BASE = N-1;
class Solution {
public:
    int fun(int index, vector<int>& height) {
        if (index == 0) return 0;

        int left = fun(index - 1, height) + abs(height[index] - height[index - 1]);
        
        int right = INT_MAX;
        if (index > 1)
            right = fun(index - 2, height) + abs(height[index] - height[index - 2]);

        return min(left, right);
    }

    int minCost(vector<int>& height) {
        int n = height.size();
        return fun(n - 1, height);
    }
};
// BY DYNAMIC PROGRAMMING
class Solution {
public:
    int fun(int index, vector<int>& height,vector<int>&dp) {
        if (index == 0) return 0;
        if(dp[index]!=0) return dp[index];
        int left = fun(index - 1, height,dp) + abs(height[index] - height[index - 1]);
        
        int right = INT_MAX;
        if (index > 1)
            right = fun(index - 2, height,dp) + abs(height[index] - height[index - 2]);

        return dp[index]=min(left, right);
    }

    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int>dp(n+1,0);
        return fun(n - 1, height,dp);
    }
};
// TABULATION
class Solution {
public:
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n, 0);
        dp[0] = 0;
        if(n>=2)
        dp[1]=abs(height[0]-height[1]);
        for (int i = 2; i < n; i++) {
            int left = dp[i - 1] + abs(height[i] - height[i - 1]);
            int right = dp[i - 2] + abs(height[i] - height[i - 2]);
            dp[i] = min(left, right);
        }

        return dp[n-1];
    }
};
