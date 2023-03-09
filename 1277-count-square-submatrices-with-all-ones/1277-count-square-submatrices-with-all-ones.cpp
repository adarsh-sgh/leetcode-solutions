class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        for(auto &&x:matrix){
            for(auto &&y:x){
                y = !y;
            }
        }
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>pref(m+1,vector<int>(n+1));

        for(int i =1;i<=m;i++){
            for(int j = 1;j<=n;j++){
                pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + matrix[i-1][j-1];
            }
        }
        int ans  = 0;
        for(int i = 0;i<m;i++){
            for(int j =0;j<n;j++){
                for(int w = 0;i+w <m && j + w<n ;w++){
                    bool valid = !(pref[i+w+1][j+w+1] + pref[i][j] 
                                - pref[i+w+1][j] - pref[i][j+w+1]);
                    
                    if(valid){
                        // cout<<i<<"i "<<j<<" j "<<w<<endl;
                         ans ++;}
                }
            }
        }
        return ans;
    }
};