class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
    //    j - nums[j] = i - nums[i] 
      map<int,int>mp;
      for(int i = 0;i< nums.size();i++){
        mp[i - nums[i]]++;
      }

      long long goodPairs = 0;
      for(auto &[x,y]:mp){
        goodPairs += 1ll * y * (y - 1)/2;
      }
      return (1ll) * nums.size() * (nums.size() - 1)/2 - goodPairs;
    }
};