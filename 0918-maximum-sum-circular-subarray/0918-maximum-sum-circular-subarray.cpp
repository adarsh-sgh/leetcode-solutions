class Solution {
public:
    long long ms = INT_MIN, msUpto = INT_MIN;
    long long mis = INT_MAX,misUpto = INT_MAX;
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;
        for(auto &&x:nums){
            totalSum += x;
            msUpto = max(1ll * x, msUpto + x);
            misUpto = min(1ll * x,misUpto + x);
            ms = max(msUpto,ms);
            mis = min(mis, misUpto);
        }
        if(ms <= 0) return ms;
        return max(ms,totalSum - mis);
    }
};