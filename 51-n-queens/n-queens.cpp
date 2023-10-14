class Solution {
public:
    vector<vector<string>>ans;
    vector<int>dx =  {-1,-1,-1,0},
                dy = {0,1,-1,-1};
    bool oob(int x,int y,vector<string>&b){
        return x >= b.size() ||  y >= b[0].size() || x < 0 || y < 0;
    }
    bool canPut(int x,int y,vector<string>&b){
        for(int d = 0;d < 4;d++){
            for(int xi = x, yi = y;!oob(xi,yi,b);xi+=dx[d],yi += dy[d]){
                if(b[xi][yi]=='Q')return false;
            }
        }
        return true;
    }


    void solve(int row,vector<string>&b){
        if(row==b.size()){
            ans.push_back(b);
            return;
            // return false;
        }
        for(int j = 0;j<b[row].size();j++){
            if(canPut(row,j,b)){
                b[row][j] = 'Q';
                solve(row+1,b);
                b[row][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string>b(n,string(n,'.'));
        solve(0,b);
        return ans;
    }
};