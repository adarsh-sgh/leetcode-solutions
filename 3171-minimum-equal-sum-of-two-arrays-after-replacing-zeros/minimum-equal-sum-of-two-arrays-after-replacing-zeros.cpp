class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long s1 = 0, s2 = 0;
        long long z1 = 0, z2 = 0;
        for(auto &x:nums1) s1 += x, z1 += x == 0;
        for(auto &x:nums2)s2+=x, z2 += x == 0;
        // assume s1 < s2
        if(s1 < s2 + z2 && z1 == 0) return -1;
        if(s2 < s1 + z1 && z2 == 0) return -1;
        return max(s1 + z1, s2 + z2);
    }
};