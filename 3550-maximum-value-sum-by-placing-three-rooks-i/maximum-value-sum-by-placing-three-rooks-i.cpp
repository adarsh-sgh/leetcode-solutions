class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        vector<set<array<int,2>>>v(n);
        for(int i = 0; i < n; i++){
            for(int j = 0;j < m;j++){
                v[i].insert({board[i][j],j});
                if(v[i].size() > 3)v[i].erase(v[i].begin());
            }
        }
        long long ans = LONG_MIN;
        // return ans;
        for(int i = 0;i<n;i++){
            auto &x = v[i];
            for(auto &y:x){
                auto &[a,j] = y;
                 for(int i1 = 0;i1<n;i1++){
            auto &x = v[i1];
            for(auto &y:x){
                auto &[a1,j1] = y;
                  for(int i2 = 0;i2<n;i2++){
            auto &x = v[i2];
            for(auto &y:x){
                auto &[a2,j2] = y;
                //cols -> j, row = i
               if(i == i1 || i1 == i2 || i == i2)continue;
               if(j == j1 || j == j2 || j1 == j2) continue;
               ans = max(ans, 0ll + a + a1 + a2);

            }
        }
            }
        }

            }
        }
           return ans;
    }
 
};