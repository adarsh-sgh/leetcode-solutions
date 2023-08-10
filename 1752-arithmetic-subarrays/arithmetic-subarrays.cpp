class Solution {
public:

    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool>ans(l.size());
        for(int i = 0;i<l.size();i++){
            int from = l[i], to = r[i];
            vector<int>v;
            for(int j = from;j<=to;j++){
                v.push_back(nums[j]);
            }   
            sort(v.begin(),v.end());
            if(v.size() < 3) {
                ans[i] = true;
                continue;
            }
            int d = v[1] - v[0];
            bool res = true;
            for(int x = 1;x< v.size();x++){
                if(v[x] - v[x-1] != d){
                    res = false;
                    break;
                }
            }
            ans[i] = res;
        }
        return ans;
    }
};