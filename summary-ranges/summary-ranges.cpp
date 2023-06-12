class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        if(nums.empty()) return {};
        int start = nums[0];

        for(int i = 1;i<=nums.size();i++){
            if(i==nums.size()||nums[i]!=nums[i-1]+1){
                if(start == nums[i-1]){
                    ans.push_back(to_string(start));
                }else{
                    ans.push_back(to_string(start)+"->"+to_string(nums[i-1]));
                }
                if(i!=nums.size())start = nums[i];
            }
        }
        return ans;
    }
};