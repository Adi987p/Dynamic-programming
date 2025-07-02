//recursion
class Solution {
public:
    void fun(int m,int n,int &count){
        if(m==0 && n==0){
            count++;
            return;
        }
        if(m<0 || n<0) return;

        fun(m-1,n,count);
        fun(m,n-1,count);
    }
    int uniquePaths(int m, int n) {
        int count = 0;
        fun(m-1,n-1,count);
        return count;
    }
};
// Memoization
class Solution {
public:
    int fun(int m,int n,vector<vector<int>>&dp){
        if(m==0 && n==0) return 1;
        if(m<0 || n<0) return 0;
        if(dp[m][n]!=-1) return dp[m][n];

        int left = fun(m-1,n,dp);
        int right = fun(m,n-1,dp);

        return dp[m][n]=left+right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return fun(m-1,n-1,dp);
    }
};
//Tabulation
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));

        dp[0][0]=1;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) dp[i][j]=1;
                else{
                    int up = 0;
                    int right =0;
                    if(i>0) up = dp[i-1][j];
                    if(j>0) right = dp[i][j-1];
                    dp[i][j] = up+right;
                }
            }
        }
        return dp[m-1][n-1];
    }
};
//Space Optimization
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>prev(n,0);

        for(int i=0;i<m;i++){
            vector<int>curr(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0)
                     curr[0]=1;
                else{
                    int up =0;
                    int right = 0;
                    if(i>0) up = prev[j];
                    if(j>0) right = curr[j-1];
                    curr[j]=up+right;
                }
            }
            prev = curr;
        }
        return prev[n-1] ;
    }
};
//OPTIMAL
class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = n+m-2;
        int r = m-1;
        double res = 1;

        for(int i=1;i<=r;i++){

            res = res*(N-r+i)/i;
        }

        return int(res);
    }
};
