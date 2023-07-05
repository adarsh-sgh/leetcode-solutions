class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        map<int,int>m;
        int j = 0;
        for(int i = 0;i<n;i++){
            m[nums[i]]++;
            while(m.rbegin()->first - m.begin()->first > 2){
                m[nums[j]]--;
                if(m[nums[j]]==0)m.erase(nums[j]);
                j++;
            }
            // j -> i valid 
            ans += i - j + 1;
        }
        return ans;
    }
};