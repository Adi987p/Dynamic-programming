// one row solution
class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        
        vector<int>prev(W+1,0);
        
        for(int i=wt[0];i<=W;i++) prev[i] = val[0];
        
        for(int index=1;index<n;index++){
            for(int weight =W;weight>=0;weight--){
                
                int notPick = prev[weight];
                int pick = -1e8;
                if(wt[index]<= weight)
                    pick = val[index]+prev[weight-wt[index]] ;
            
                prev[weight] = max(pick,notPick);
            }
        }
        
        return prev[W];
    }
};
