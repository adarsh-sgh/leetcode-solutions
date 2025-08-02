class Solution {
public:
    int minDistance(string word1, string word2) {
       vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,1e6));
       dp[0][0] = 0;
       if(word1.size() == 0 || word2.size()==0) return max(word1.size(), word2.size());
       dp[1][0] = dp[0][1] = 1;
        for(int i=0;i<word1.length();i++){
            for(int j=0;j<word2.length();j++){
                dp[i][0] = i;
                dp[0][j] = j;
                if(word1[i]==word2[j]){
                    dp[i+1][j+1]=dp[i][j];
                }else{
                    dp[i+1][j+1]=1+min({dp[i+1][j],dp[i][j+1],dp[i][j]});
                }
            }
        }
        // int lcs= dp[word1.size()][word2.size()];
        return dp.back().back();
    }
};

// horse
// ros

// 9-5=4