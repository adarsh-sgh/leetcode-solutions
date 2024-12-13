class Solution {
public:
    long long findScore(vector<int>& nums) {
        set<array<int,2>>se;
        for(int i = 0; i < nums.size(); i++){
            se.insert({nums[i], i});
        }
        int n = nums.size();
        vector<int>marked(n);
        long long scr = 0;
        for(auto &[x,i]:se){
            if(marked[i]){
               continue; 
            }
            marked[i] = true;
            if(i - 1 >= 0) marked[i-1] = true;
            if(i+1 < n) marked[i+1]  = true;
            scr += x;
        }
        return scr;
    }
};