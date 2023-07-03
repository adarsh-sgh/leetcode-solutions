class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
  long long miss = 1, added  = 0,i = 0; 
  while(miss<=n){
    if(i<nums.size() && nums[i]<=miss){
      miss += nums[i];
      i++;
    }else{
      miss+=miss;
      added++;
    }
  }
  return added;
}
};