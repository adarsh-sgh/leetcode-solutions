class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
       // if k se chhota hai koi -1
       // return k se bade distinct integers
       set<int>se;
       for(auto &x:nums){
        if(x < k) return -1;
        if(x == k)continue;
        se.insert(x);
       } 
       return se.size();
    }
};