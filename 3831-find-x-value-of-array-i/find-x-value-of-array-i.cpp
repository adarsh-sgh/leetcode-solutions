class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        for (auto& x : nums)
            x = x % k;
        // now nums[i] <= 5 (same as k)
        // dp[i][x] = n -> count of subarrays ending at i which leave reminder x
        // dp[i][x] = (nums[i] % k == x) + dp[i-1][c] such that c * nums[i] % k
        // = x => x * modinv(nums[i]) % k
        int n = nums.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1));

        for (int i = 1; i <= n; i++) {
            for (int x = 0; x < k; x++) {
                // ya to yahin x remainder aa jaye
                dp[i][x] = (nums[i - 1] % k == x);
                // ya kisi purane se rishta jodo jo remainder x kar de
                for (int j = 0; j < k; j++) {
                    if (1ll * j * nums[i - 1] % k == x) {
                        dp[i][x] += dp[i - 1][j];
                    }
                }
            }
        }
        // return {};
        vector<long long>ans(k);
        for(auto &it:dp){
            for(int x = 0; x < k;x++){
                ans[x] += it[x];
            }
        }

        return ans;
    }
};

// non empty subarray such that
// prod(subarray) %k == x

// nums[i] <= 5