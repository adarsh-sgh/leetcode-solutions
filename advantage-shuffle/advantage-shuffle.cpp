class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>m;
        for(auto &&x:nums1)m[x]++;
        vector<int>ans(nums1.size(),-1);
        for(int i = 0;i<nums2.size();i++){
            auto x = nums2[i];
            auto ub = m.upper_bound(x);
            if(ub==m.end())continue;
            ans[i] = ub->first;
            ub->second--;
            if(ub->second==0)m.erase(ub);
        }
        auto it = m.begin();
        for(int i = 0;i<ans.size();i++){
            if(ans[i]==-1){
                ans[i] = it->first;
                it->second--;
                if(it->second==0)it++;
            }
        }
        return ans;
    }
};