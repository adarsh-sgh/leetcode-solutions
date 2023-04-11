class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        static auto  oob = [&](int x,int y){
            return x < 0 || y < 0 || x >= m||y>=n;
        };
        // vector<vector<int>>ans(m,vector<int>(n));
        vector<pair<int,int>>d = {
          {0,1},
          {0,-1},

          {1,0},
          {-1,0},

          {1,1},
          {1,-1},
          {-1,1},
          {-1,-1},
        };
        for(int x = 0;x<m;x++){
            for(int y = 0;y<n;y++){
                int liveCount = 0;
                for(int i = 0;i<8;i++){
                    int xn = x + d[i].first;
                    int yn = y + d[i].second;
                    if(oob(xn,yn)) continue;
                    // liveCount += board[xn][yn];
                    liveCount += board[xn][yn] & 1;
                }
                // cout<<x<<' '<<y<<' '<<liveCount<<'\n';
                if(liveCount == 3){
                    // ans[x][y] = 1;
                    board[x][y] |= 2;
                }else if(liveCount < 2||liveCount >3){
                    // ans[x][y] = 0;
                    board[x][y] &= 1;
                }else{
                    board[x][y] |= (board[x][y]<<1);
                    // ans[x][y] = board[x][y];
                }
            }
        }
        for(auto &&x:board){
            for(auto &&j:x){
                j = j >>1 ;
            }
        }
        // board = ans;
        

    }
};