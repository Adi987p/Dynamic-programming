class Solution {
  public:
 void printAll(string &str1, string &str2, int len1, int len2,
                char data[], int indx1, int indx2, int currlcs,
                vector<string>& ans, int lcslen,
                vector<vector<int>>& dp) {

    if (currlcs == lcslen) {
      data[currlcs] = '\0';
      ans.push_back(string(data));
      return;
    }

    if (indx1 == len1 || indx2 == len2) return;

    for (char ch = 'a'; ch <= 'z'; ch++) {
      bool done = false;

      for (int i = indx1; i < len1; i++) {
        if (str1[i] == ch) {
          for (int j = indx2; j < len2; j++) {
            if (str2[j] == ch &&
                dp[i + 1][j + 1] == lcslen - currlcs - 1) {
              data[currlcs] = ch;
              printAll(str1, str2, len1, len2, data, i + 1, j + 1,
                       currlcs + 1, ans, lcslen, dp);
              done = true;
              break;
            }
          }
        }
        if (done) break;
      }
    }
  }

  vector<string> allLCS(string &s1, string &s2) {
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = n - 1; i >= 0; i--) {
      for (int j = m - 1; j >= 0; j--) {
        if (s1[i] == s2[j])
          dp[i][j] = 1 + dp[i + 1][j + 1];
        else
          dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
      }
    }

    vector<string> store;
    char data[n + 1];
    printAll(s1, s2, n, m, data, 0, 0, 0, store, dp[0][0], dp);

    sort(store.begin(), store.end());
    store.erase(unique(store.begin(), store.end()), store.end());

    return store;
  }
};

// space Optimization

class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int n = s1.size();
        int m = s2.size();
        
        vector<int>prev(m+1,0),curr(m+1,0);
        
        int maxi=0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    if(prev[j-1]!=0)
                        curr[j]=1+prev[j-1];
                    else
                        curr[j]=1;
                }
                else curr[j]=0;
                
                if(maxi<curr[j]) maxi = curr[j];
            }
            prev = curr;
        }
        
        return maxi;
    }
};
