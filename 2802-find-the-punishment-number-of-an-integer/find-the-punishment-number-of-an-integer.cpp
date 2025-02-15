class Solution {
public:
    // i ke aage ke elements se sum bna do
    bool dfs(int i, string &s, int sum){
        if(i == s.size()) return sum == 0;
        int curr = 0;
        bool ans = false;
        for(int j = i;j<s.size();j++){
            // [i,j] tak curr rahega
            curr = curr * 10 + (s[j] - '0');
            if(curr > sum) break;
            ans |= dfs(j+1,s,sum - curr); 
        }
        return ans;
    }
    bool isValid(int i) {
        int sq = i * i;
        // i <= 1k => ss.size() <= 7
        string ss = to_string(sq);
        return dfs(0,ss,i);
        // dp[i][x] => i digs lekar x sum bana sakte ho ? (sum < i)
        // dp[i][x] => dp[j][x-num]  && ss.substr(j,i) == num
        // vector<vector<int>> dp(ss.size(), vector<int>(i + 1));
        // for (int j = 0; j < ss.size(); j++) {
        //     // make sum = x
        //     for (int x = 0; x <= i; x++) {
        //         for (int k = 0; k <= j; k++) {
        //             // [k,j] last substr
        //             int num = stoi(ss.substr(k, j - k + 1));
        //             if(k == 0){
        //                 dp[j][x] |= (num == x);
        //             }else if(x >= num){
        //                 dp[j][x] |= dp[k-1][x - num];
        //             }
        //             if(dp[j][x])break;
        //         }
        //     }
        // }
        // return dp[ss.size() - 1][i];
    }
    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (isValid(i)) {
                ans += i * i;
            }
        }
        return ans;
    }
};