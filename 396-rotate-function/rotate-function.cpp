class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
      long long sm = accumulate(nums.begin(), nums.end(), 0ll);
      int ans = 0;
      int f0 = 0;
      for(int i = 0;i < nums.size();i++){
        f0 += i * nums[i];
      }
      ans = f0;
      int fp = f0;
      int c = nums.size() - 1;
      for(int i = 1;i< nums.size();i++){
        // cout<<ans<<' ';
        int fi = fp - nums.size() * nums[c] + sm;
        fp = fi;
        c--;
        ans = max(ans, fi);
      }
      return ans;
    }
};

// 25 + 15 - 12
//

// 0 1 2 3 4 
// post rotation becomes
// 1 2 3 4 0
// 2 3 4 0 1

// highest number gets zeroed
// rest all increase by 1 

// scr(i) = scr(i-1) - 2 * nums[c] + sum(nums)
// c=> cursor to make zero