class Solution {
public:

    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
       // binary search ?  
       int n = mat.size(), m = mat[0].size();
       auto good = [&](int l){
        set<int>se;
        for(int i = 0;i<=l;i++){
            se.insert(arr[i]);
        }
        for(int i = 0;i<n;i++){
            bool gg = true;
            for(int j = 0;j<m;j++){
                if(!se.count(mat[i][j])){
                    gg = false;
                    break;
                }
            }
            if(gg) return gg;
        }
        for(int j = 0;j<m;j++){
            bool gg = true;
            for(int i =0;i<n;i++){
                if(!se.count(mat[i][j])){
                    gg = false;
                    break;
                }
            }
            if(gg) return gg;
        }
        return false;
       };

       int l = 0, r = arr.size() - 1;
       while(l < r){
        int m = (l + r) >> 1;
        if(good(m)){
            r = m;
        }else{
            l = m + 1;
        }
       }
       return l;
    }
};