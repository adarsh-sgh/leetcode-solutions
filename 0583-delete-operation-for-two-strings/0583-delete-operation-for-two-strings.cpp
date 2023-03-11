class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>>v(m+1,vector<int>(n+1));
        for(int i = 0;i<=m;i++){
            v[i][0] = i;
        }
        for(int j = 0;j<=n;j++){
            v[0][j] = j;
        }
        for(int i =0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(word1[i] == word2[j]){
                    v[i+1][j+1] = v[i][j];
                }else{
                    v[i+1][j+1] = min(v[i][j+1],v[i+1][j]) + 1;

                }
            }
        }
        return v.back().back();

    }
};