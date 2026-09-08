class Solution {
public:
    vector<int> dp;
    int ways(string &s, int i){
        if(i >= s.size()) return 1;
        if(s[i] =='0') return 0;
        if(i == s.size() -1) return 1;
        if(dp[i] != -1) return dp[i];
        if(s[i] =='1') return dp[i] = ways(s, i+1) + ways(s, i+2);
        if(s[i] == '2' && s[i+1] <= '6') return dp[i] = ways(s, i+1) + ways(s, i+2);
        return dp[i] = ways(s, i+1);

    }
    int numDecodings(string s) {
        dp.resize(s.size(), -1);
       return ways(s, 0) ;
    }
};