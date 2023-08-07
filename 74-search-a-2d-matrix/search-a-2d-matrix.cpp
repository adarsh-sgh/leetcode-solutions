class Solution {
public:
   
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        auto index = [&](int x,int y)->int{
            return x * n + y;
        };
        auto at = [&](int i)->int{
            int x = i / n;
            int y = i % n;
            return matrix[x][y];
        };
        int l = 0, r = index(m-1,n-1);
        while(l < r){
            int m = (l + r) >> 1;
            if(at(m) >= target){
                r = m;
            }else{
                l = m + 1;
            }
        }
        return at(l)==target;
    }
};