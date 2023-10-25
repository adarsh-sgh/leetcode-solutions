class Solution {
public:
    int mod = 1e9+7;
    int rectangleArea(vector<vector<int>>& rectangles) {
        set<int>sx,sy;
        for(auto &r:rectangles){
            sx.insert(r[0]);
            sx.insert(r[2]);
            sy.insert(r[1]);
            sy.insert(r[3]);
        }
        map<int,int>mx,my;
        auto it = sx.begin();
        for(int i = 0;i<sx.size();i++){
            mx[*it] = i;
            ++it;
        }
        it = sy.begin();
        for(int i = 0;i< sy.size();i++){
            my[*it] = i;
            ++it;
        }
        //inverse maps
        vector<int>imx(sx.begin(),sx.end());
        vector<int>imy(sy.begin(),sy.end());
        vector<vector<bool>>rct(mx.size(),vector<bool>(my.size()));
        for(auto &r:rectangles){
            // notice that we are excluding the final coordinate while couting area
            // to calc. area of rect with (0,0) and (1,1) just count (0,0) and 
            // not 3 points on right and top boundaries (1,0) (0,1) & (1,1)
            for(int i = mx[r[0]];i<mx[r[2]];i++){
                for(int j = my[r[1]];j<my[r[3]];j++){
                    rct[i][j] = 1;
                }
            }
        }
        long long ans = 0;
        for(int i =0;i<rct.size();i++){
            for(int j = 0;j<rct[0].size();j++){
                if(rct[i][j]){
                    ans += 1ll * (imx[i+1] - imx[i]) * (imy[j+1] - imy[j]);
                    ans %= mod;
                }
            }
        }
        return ans;
    }
};