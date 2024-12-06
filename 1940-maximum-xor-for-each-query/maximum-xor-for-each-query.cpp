class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int mb) {
        // ~xor(nums)  pick mb most significant bits and make rest as zero
        vector<int> ans;
        int xr = 0;
        for (auto& x : nums) {
            xr ^= x;
            int curr = (~xr) & ((1 << mb) - 1);
            ans.push_back(curr);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};