class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
       // order doesn't matter
    //    sort(nums.begin(), nums.end());
       map<int,int>mp;
       for(int i = 0;i < nums.size();i++){
        for(int j = i+1;j< nums.size();j++){
            mp[nums[i] * nums[j]]++;
        }
       }
       int ans = 0;
       for(auto &[x,y]:mp){
        // yc2
        ans += y * (y-1) /2; 
       }

       return ans * 4 * 2;
    }
};