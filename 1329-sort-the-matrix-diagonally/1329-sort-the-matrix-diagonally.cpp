class Solution {
public:
vector<vector<int>> m;
    bool oob(int x,int y){
    return x >= m.size() || x < 0 || y >= m[0].size() || y < 0;
    }

    void dfs(int i,int j,vector<int>&v){
        if(oob(i,j)){
            sort(v.begin(),v.end());
            return;
        }
        v.push_back(m[i][j]);
        dfs(i+1,j+1,v);
        m[i][j] = v.back();
        v.pop_back();
    }
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        m = mat;
        for(int i  = 0;i<m.size();i++){
            vector<int> v;
            dfs(i,0,v);
        }
        for(int j = 1;j < m[0].size();j++){
            vector<int>v;
            dfs(0,j,v);
        }
        return m;
    }
};