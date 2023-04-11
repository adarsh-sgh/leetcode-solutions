class Solution {
public:
    vector<vector<int>>dp;
    int n;
    string s;
    vector<vector<string>>ans;
   void pn(int index,vector<string>&v){
        if(index == n){
            ans.push_back(v);
        }
        for(int i = index;i<n;i++){
            if(!dp[index][i])continue;
            v.push_back(s.substr(index,i-index+1));
            pn(i+1,v);
            v.pop_back();
        }
    }
    vector<vector<string>> partition(string S) {
        s = S;
         n = s.size();
        dp.resize(n,vector<int>(n));
        for(int i = n-1;i>=0;i--){
            for(int j = i;j<n;j++){
                 dp[i][j] = (i==j )|| ((dp[i+1][j-1] ||( j == i+1)) && (s[i] == s[j]));
            }
        }
        // cout<<dp[0][1]<<dp[0][0];
        vector<string> tmp;
         pn(0,tmp);
         return ans;
    }
};