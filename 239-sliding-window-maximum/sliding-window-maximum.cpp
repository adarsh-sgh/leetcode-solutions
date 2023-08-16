class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;
        for(int i = 0;i<nums.size();i++){
            if(i-k==dq.front())dq.pop_front();
            while(dq.size() && nums[dq.back()]< nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i-k+1 >= 0)ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};