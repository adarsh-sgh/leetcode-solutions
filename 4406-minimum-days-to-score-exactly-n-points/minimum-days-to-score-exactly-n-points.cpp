class Solution {
public:
    // closest we can go to x in one streak, and days it would take  
    int days = 0;
    int closest(int x){
        // find p such that p * (p + 1) = 2 * x;
        // we can binary search
        int l = 0, r = x;
        while(l < r){
            // ... true, true,false false false..
            int m = (l + r + 1)/2;
            if(m * (m+1) <= 2 * x){
                // true
                l = m;
            }else{
                r = m - 1;
            }
        }
        // l * (l + 1) is the closest
        days += l;
        return x - l * (l+1)/2;
    }

    int minDays(int n) {
      vector<int>sums = {1};
      for(int i = 2;i < 1e3;i++){
        int nxt = sums.back() + i;
        if(nxt > 1e5)break;
        sums.push_back(nxt);
      }
      set<int>se(sums.begin(), sums.end());
      // each element can be picked any number of times 
      // dp[i] => i banane ke min days
      // dp[i] = for each element in sums say x, dp[i - x] + 2 or 1 if sums has i
      vector<int>dp(n+1, 1e6);
      dp[0] = 0;
      dp[1] = 1;
      for(int i = 2;i<=n;i++){
        // check if i in sums
        auto lb = lower_bound(sums.begin(), sums.end(), i);
        if(lb != sums.end() && *lb == i){
            dp[i] = lb - sums.begin() + 1;
            continue;
        }
        for(auto &x:se){
            if(x > i)break;
            dp[i] = min(dp[i], dp[i - x] + 1 + dp[x]);
        }
      }
      return dp.back();
    }
};