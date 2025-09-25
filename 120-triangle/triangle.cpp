class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int inf = 1e8;
        for(int i = 1;i< triangle.size();i++){
            for(int j = 0;j < triangle[i].size();j++){
                int x = inf, y = inf;
                if(j != triangle[i].size() - 1){
                    x = triangle[i-1][j];
                }
                if(j != 0){
                    y = triangle[i-1][j-1];
                }
                triangle[i][j] += min(x,y);
            }
        }
        return *min_element(triangle.back().begin(), triangle.back().end());
    }
};