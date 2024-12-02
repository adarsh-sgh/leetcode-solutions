class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int k = 1000;
        map<int,int>mp;
       for(auto &x:nums)mp[x]++;
       unordered_set<int> se(nums.begin(),nums.end());
       int sum = accumulate(nums.begin(),nums.end(),0);
       int ans = INT_MIN;
       for(int j:se){
        for(int i:se){
            if(i == j && mp[i] < 2){
                continue;
            }
            if(sum - 2 * i - j == 0){
                ans = max(ans, j);
            }
        }
       } 
       return ans;
    }
};