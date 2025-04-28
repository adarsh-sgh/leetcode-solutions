class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
      int n = nums.size();
      // subarrays ending at i with score < k can be found with bs
      vector<long long>p(n+1);
      for(int i = 0;i< n;i++)p[i+1] = p[i] + nums[i];
      // i to j subarray ka score < k hai kya ?
      auto good = [&](int i, int j){
        if(j >= n) return false;
        return (p[j+1] - p[i])*1ll * (j - i + 1) < k;
      };

      long long ans = 0;
      for(int i = 0;i < nums.size();i++){
        // f f f, t t t 
        int l = 0, r = i;
        while(l < r){
            int m = (l + r)/2;
            if(good(m, i)){
                r = m;
            }else{
                l = m + 1;
            }
        }
        if(good(l, i)){
          ans += i - l + 1;  
        }
      }    
      return ans;
    }
};