// Recursion
class Solution {
  public:
    void fun(int index,vector<vector<int>>&arr,int sum,int &Max,int previous){
        if(index == arr.size()){
            Max = max(Max,sum);
            return;
        }
        
        for(int i=0;i<3;i++){
            if(i!=previous)
                fun(index+1,arr,sum+arr[index][i],Max,i);
        }
    }
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int Max=INT_MIN;
        fun(0,arr,0,Max,-1);
        return Max;
    }
};
// Dynamic programming
class Solution {
  public:
     int fun(int index, int prev, vector<vector<int>>& arr, vector<vector<int>>& dp) {
        if (index == arr.size()) return 0;
        if (dp[index][prev] != -1) return dp[index][prev];
        
        int maxPoints = 0;
        for (int task = 0; task < 3; task++) {
            if (task != prev) {
                maxPoints = max(maxPoints, arr[index][task] + fun(index + 1, task, arr, dp));
            }
        }
        
        return dp[index][prev] = maxPoints;
    }
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(4,-1));
        
        return fun(0,3,arr,dp);
    }
};
//Tabulation
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& points) {
        // Code here
        int n = points.size();
        vector<vector<int>> dp(n, vector<int>(4, 0));  // dp[day][last]

        // Base case for day 0
        dp[0][0] = max(points[0][1], points[0][2]);
        dp[0][1] = max(points[0][0], points[0][2]);
        dp[0][2] = max(points[0][0], points[0][1]);
        dp[0][3] = max({points[0][0], points[0][1], points[0][2]});

        for (int day = 1; day < n; day++) {
            for (int last = 0; last < 4; last++) {
                dp[day][last] = 0;
                for (int task = 0; task < 3; task++) {
                    if (task != last) {
                        int point = points[day][task] + dp[day - 1][task];
                        dp[day][last] = max(dp[day][last], point);
                    }
                }
            }
        }

        // Return the answer starting from day n-1, with no task done the previous day
        return dp[n - 1][3];
    }
};
// space optimization
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& points) {
        // Code here
        int n = points.size();
        vector<int>prev(4,-1);  // dp[day][last]

        // Base case for day 0
        prev[0] = max(points[0][1], points[0][2]);
        prev[1] = max(points[0][0], points[0][2]);
        prev[2] = max(points[0][0], points[0][1]);
        prev[3] = max({points[0][0], points[0][1], points[0][2]});

        for (int day = 1; day < n; day++) {
            
             vector<int>curr(4,0);
             
            for (int last = 0; last < 4; last++) {
                
                curr[last]=0;
                
                for (int task = 0; task < 3; task++) {
                    
                    if (task != last) {
                        
                        int point = points[day][task] + prev[task];
                        curr[last] = max(curr[last], point);
                    }
                }
            }
            
            prev = curr;
        }

        // Return the answer starting from day n-1, with no task done the previous day
        return prev[3];
    }
};
