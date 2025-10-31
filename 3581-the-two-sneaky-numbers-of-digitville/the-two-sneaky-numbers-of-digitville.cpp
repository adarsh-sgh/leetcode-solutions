class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
       unordered_map<int,int>mp;
       vector<int>ans;
       for(auto &x:nums){
        if(mp.count(x))ans.push_back(x);
        mp[x]++;
       } 
       return ans;
    }
};