class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        for(auto &r:box){
            int t = r.size() - 1;
            for(int i = r.size()- 1;i>=0;i--){
                if(r[i] == '*'){
                    t = i - 1;
                    continue;
                }else if(r[i] == '#'){
                    swap(r[i], r[t]);
                    t--;
                }
            }
        }
        int n = box.size(), m = box[0].size();
        // return box;
        vector<vector<char>>ans(m,vector<char>(n));
        for(int i = 0;i<n;i++){
            for(int j = 0; j < m; j++){
                ans[j][n - i - 1] = box[i][j];
            }
        }
        return ans;
    }
};