class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
       vector<int>ans;
       for(auto &x:nums){
        vector<int>tmp;
        while(x){
            tmp.push_back(x%10);
            x/=10;
        }
        while(tmp.size()){
            ans.push_back(tmp.back());
            tmp.pop_back();
        }
       } 
       return ans;
    }
};