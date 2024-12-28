class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>p(n + 1);
        for(int i = 0;i<n;i++){
            p[i + 1] = p[i] + nums[i];
        }
        // v1[i] => x : sum(v[x]..v[x + k-1]) is max among all index upto i
        vector<int>v1(n);
        int mx = -1;
        for(int i = 0;i + k - 1 < n;i++){
           if(p[i+k] - p[i] > mx){
            mx = p[i+k] - p[i];
            v1[i] = i;
           }else{
            v1[i] = v1[i-1];
           }
        }
        // in reverse
        mx = -1;
        vector<int>v2(n);
        for(int i = n - k;i >= 0;i--){
           if(p[i+k] - p[i] >= mx){
            mx = p[i+k] - p[i];
            v2[i] = i;
           }else{
            v2[i] = v2[i+1];
           }
        }
        // i => starting of mid segment
        vector<int>ans;
        mx = -1;
        // sum i..i+k-1
        auto sm = [&](int i){
           return p[i+k] - p[i];
        };
        for(int i = k;i + 2 * k -1<n;i++){
            //i - k...i - 1 || i...i + k - 1 || i + k ... i + 2 * k - 1
            if(sm(v1[i-k]) + sm(v2[i + k]) + p[i+k] - p[i] > mx){
                mx = sm(v1[i-k]) + sm(v2[i + k]) + p[i+k] - p[i];
                ans = {v1[i-k], i, v2[i + k]};
            }
        }
        return ans;
    }
};