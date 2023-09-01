class Solution {
public:
    // vector<vector<int>>v;
    // int indexOf(vector<int>&v,int val){
    //     auto lb = lower_bound(v.begin(),v.end(),val);
    //     if(lb==v.end() || *lb != val)return -1;
    //     return lb - v.begin();
    // }
    // void ms(bool is0,int i){
    //     int res = ms(is0,i-1) + v[is0][i];
    //     int in = indexOf(v[!is0],v[is0][i]);
    //     if(in==-1)return res;
    //     return max(res,ms(!is0,in));
    // }
    int mod = 1e9 + 7;
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int p1 = 0, p2 = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        vector<long long>pf1(n1+1),pf2(n2+1);
        while(p1 < nums1.size() && p2 < nums2.size()){
            if(nums1[p1]==nums2[p2]){
                long long curr = max(pf1[p1],pf2[p2]) + nums1[p1];
                pf1[p1+1] = curr;
                pf2[p2+1] = curr;
                p1++;
                p2++;
            }else if (nums1[p1] < nums2[p2]){
                pf1[p1 + 1] = pf1[p1] + nums1[p1];
                p1++;
            }else{
                pf2[p2 + 1] = pf2[p2] + nums2[p2];
                p2++;
            }
        }
        while(p1 < nums1.size()){
            pf1[p1+1] = pf1[p1] + nums1[p1];
            p1++;
        }
        while(p2 < nums2.size()){
            pf2[p2+1] = pf2[p2] + nums2[p2];
            p2++;
        }
        return max(pf1.back(),pf2.back()) % mod;
    }
};