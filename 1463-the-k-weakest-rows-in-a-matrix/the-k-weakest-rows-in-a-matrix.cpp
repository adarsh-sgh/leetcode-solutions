class Solution {
public:
    int soldierCount(vector<int>&v){
        int l = 0, r = v.size() -1 ;
        while( l < r){
            int m = (l + r)>>1;
            if(v[m]){
                l = m + 1;
            }else{
                r = m;
            }
        }
        if(v[l])l++;
        return l;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int>weakness[101];
        for(int i = mat.size() -1; i >= 0; i--){
            auto &v = mat[i];
            weakness[100 - soldierCount(v)].push_back(i);
        }
        vector<int>ans(k);
        int p = 100;
        int ki = 0;
        // return ans;
        while( ki < k){
            while(weakness[p].empty())p--;
            ans[ki] = weakness[p].back();
            weakness[p].pop_back();
            ki++;
        }
        return ans;
    }
};

