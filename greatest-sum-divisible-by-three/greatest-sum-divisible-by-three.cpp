class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int>v(3);
        int sum = 0;

        priority_queue<int>q1,q2;
        // int q2 = INT_MAX;
        for(int i = 0;i<nums.size();i++){
            sum+=nums[i];
            int rem = nums[i]%3;
            if(rem==2){
                q2.push(nums[i]);
                if(q2.size()>2)q2.pop();
            }
            if(rem == 1){
                q1.push(nums[i]);
                if(q1.size()>2)q1.pop();
            }
        }
        if(sum%3==0)return sum;
        if(sum%3==1){
            if(q1.size() > 1) q1.pop();
            if(q2.size() < 2) return sum - q1.top();
            int s2 = q2.top();q2.pop();
            s2 += q2.top();
            if(q1.empty()) return sum - s2;
            return sum - min(q1.top(),s2);
        }
        if(q2.size() > 1) q2.pop();
        if(q1.size()<2) return sum - q2.top();
        int s1 = q1.top();
        q1.pop();
        s1 += q1.top();
        if(q2.empty()) return sum - s1;
        return sum - min(q2.top(),s1);
    }
};