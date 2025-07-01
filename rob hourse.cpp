// recursion
class Solution {
public:
    void fun(int index,int n, vector<int>&nums,int sum,int &ans){
        if(index >= n)
        {
            ans=max(ans,sum);
            return;
        }
        fun(index+2,n,nums,sum+nums[index],ans);
        fun(index+1,n,nums,sum,ans);
    }
    int rob(vector<int>& nums) {
       int n = nums.size();
       int ans = INT_MIN;
       fun(0,n,nums,0,ans);
       return ans ;
    }
};
//Memoization
class Solution {
public:
    int fun(int index, int n, vector<int>& nums, vector<int>& dp) {
        if (index >= n) return 0;

        if (dp[index] != -1) return dp[index];

        // Pick current house
        int pick = nums[index] + fun(index + 2, n, nums, dp);

        // Skip current house
        int nonPick = fun(index + 1, n, nums, dp);

        return dp[index] = max(pick, nonPick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return fun(0, n, nums, dp);
    }
};

//Tabulation
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        dp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            int take = nums[i];
            if(i>1) take+=dp[i - 2];
            int nonTake = 0 + dp[i - 1];
            dp[i] = max(take, nonTake);
        }
        return dp[n-1];
    }
};

// Sapce optimization
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;
        for (int i = 1; i < n; i++) {
            int take = nums[i];
            if(i>1) take+=prev2;
            int nontake = prev;
            int curri = max(take, nontake);

            prev2 = prev;
            prev = curri;
        }

        return prev;
    }
};

