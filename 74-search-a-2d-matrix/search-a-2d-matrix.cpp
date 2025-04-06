class Solution {
public:
     int m, n;
    int id(int x,int y){
        return y + x * n;
    }
    // x, y
    array<int,2> coord(int id){
        int x = id / n;
        int y = id % n;
        return {x,y};
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       // low = 0, 0 0
       // 2, 3 => 11 => 
       // high = n, m
        m = matrix.size();n = matrix[0].size(); 
        int l = 0, r = id(m-1, n-1);
        while(l < r){
            int m = (l + r)/2;
            auto [x,y] = coord(m);
            if(matrix[x][y] >= target){
                r = m;
            }else{
                l = m + 1;
            }
        }
        auto [x,y] = coord(l);
        return matrix[x][y] == target;
    }
};