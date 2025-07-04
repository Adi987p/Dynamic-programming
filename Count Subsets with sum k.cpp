//recursion
class Solution {
  public:
    
    int solve(vector<int> &arr,int i,vector<vector<int>> &dp,int target)
    {
        if(target<0)
        return 0;
        
        if(i==arr.size())
        {
            if(target==0)
            return 1;
            else
            return 0;
        }
        
        // if(dp[target][i]!=-1)
        // return dp[target][i];
        
        int t=solve(arr,i+1,dp,target-arr[i]);
        int nt=solve(arr,i+1,dp,target);
        
        return t+nt;
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(target+1,vector<int>(n+1,-1));
        return solve(arr,0,dp,target);
    }
    
};

// memoization

class Solution {
  public:
    
    int solve(vector<int> &arr,int i,vector<vector<int>> &dp,int target)
    {
        if(target<0)
        return 0;
        
        if(i==arr.size())
        {
            if(target==0)
            return 1;
            else
            return 0;
        }
        
        if(dp[target][i]!=-1)
        return dp[target][i];
        
        int t=solve(arr,i+1,dp,target-arr[i]);
        int nt=solve(arr,i+1,dp,target);
        
        return dp[target][i]=t+nt;
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(target+1,vector<int>(n+1,-1));
        return solve(arr,0,dp,target);
    }
    
};

// tabulation
