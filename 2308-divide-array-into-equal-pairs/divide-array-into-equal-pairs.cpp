class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<int,int>mp;
        for(auto &x:nums){
            mp[x]++;
        }
        for(auto &[x,y]:mp){
            if(y%2) return false;
        }
        return true;
    }
};