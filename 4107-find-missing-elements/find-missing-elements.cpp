class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
       int min = *min_element(nums.begin(), nums.end());
       int mx = *max_element(nums.begin(), nums.end());
       set<int> se (nums.begin(), nums.end());
       vector<int>ans;
       for(int i = min; i <= mx;i++){
        if(!se.count(i)){
            ans.push_back(i);
        }
       }
       return ans;
    }
};