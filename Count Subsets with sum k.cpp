//recursion

class Solution {
  public:
    int fun(int index, vector<int>&a,int k){
        if(index==0){
            if(k==0 && a[index]==0) return 2;
            if(k==0 || k==a[0]) return 1;
            return 0;
        }
        
        int notTake = fun(index-1,a,k);
        int take = 0;
        if(k>=a[index])
            take = fun(index-1,a,k-a[index]);
            
        return notTake+take;
    }
    int perfectSum(vector<int>& a, int k) {
        // code here
        int n = a.size();
        return fun(n-1,a,k);
    }
};

// memoization


class Solution {
  public:
    int fun(int index, vector<int>&a,int k,vector<vector<int>>&dp){
        if(index==0){
            if(k==0 && a[index]==0) return 2;
            if(k==0 || k==a[0]) return 1;
            return 0;
        }
        if(dp[index][k]!=-1) return dp[index][k];
        
        int notTake = fun(index-1,a,k,dp);
        int take = 0;
        if(k>=a[index])
            take = fun(index-1,a,k-a[index],dp);
            
        return dp[index][k] = notTake+take;
    }
    int perfectSum(vector<int>& a, int k) {
        // code here
        int n = a.size();
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return fun(n-1,a,k,dp);
    }
};
                                                                                
// tabulation

class Solution {
  public:
    int perfectSum(vector<int>& a, int k) {
        // code here
        int n = a.size();
        vector<vector<int>>dp(n,vector<int>(k+1,0));
        
        if(a[0]==0)
            dp[0][0]=2;
        else dp[0][0]=1;
        
        if(a[0]!=0 && k>=a[0]) dp[0][a[0]]=1;
            
        for(int i=1;i<n;i++){
            for(int sum = 0;sum<=k;sum++){
                
                int notTake = dp[i-1][sum];
                int take = 0;
                if(sum>=a[i])
                    take = dp[i-1][sum-a[i]];
            
                dp[i][sum] = notTake+take;
            }
        }
        return dp[n-1][k];
    }
};

// space optimization

class Solution {
  public:
    int perfectSum(vector<int>& a, int k) {
        // code here
        int n = a.size();
        vector<int>prev(k+1,0),curr(k+1,0);
        
        if(a[0]==0)
            prev[0]=2;
        else prev[0]=1;
        
        if(a[0]!=0 && k>=a[0]) prev[a[0]]=1;
            
        for(int i=1;i<n;i++){
            for(int sum = 0;sum<=k;sum++){
                
                int notTake = prev[sum];
                int take = 0;
                if(sum>=a[i])
                    take = prev[sum-a[i]];
            
                curr[sum] = notTake+take;
            }
            prev = curr;
        }
        return prev[k];
    }
};

                                                                                
                                                                                
