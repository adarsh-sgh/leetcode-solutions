class Solution {
public:
    bool isRobotBounded(string instructions) {
        pair<int,int> pos = {0,0};
        //
        vector<pair<int,int>>d = 
        {
        {0,1},//N
        {1,0},//E
        {0,-1},
        {-1,0}
        };
        int di = 0;
        for(int i =0;i<4;i++){
            for(auto &&c:instructions){
                if(c=='R'){
                    di = (di+1) %4;
                }else if(c=='L'){
                    di = (di-1 + 4) %4;
                }else if(c == 'G'){
                   pos.first += d[di].first;
                   pos.second += d[di].second;
                }
            }
        }
        return !pos.first && !pos.second;
    }
};