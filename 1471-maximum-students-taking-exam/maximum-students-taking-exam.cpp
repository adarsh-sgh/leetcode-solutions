class Solution {
public:
    vector<vector<char>>seats;
    inline bool isset(int bm,int i){
        return bm & (1<<i);
    }
    bool isValid(int prev,int curr){
        int o = prev | curr;
        if(isset(curr,0) && isset(o,1))return false;
        for(int i = 1;i<8;i++){
            if(isset(curr,i) && (isset(o,i-1)||isset(o,i+1)))return false;
        }
        return true;
    }
    int dp[1<<8][8] = {-1};
    // vector<vector<int>>dp;
    int mst(int prev,int index){
        if(index == seats.size()) return 0;
        int curr = 0;
        auto &x = seats[index];
        int &res = dp[prev][index];
        if(res != -1) return res;
        for(int i = 0;i<x.size();i++){
            if(x[i]=='.'){
                curr |= (1<<i);
            }
        }

         res = mst(0,index+1);
        for (int s=curr; s; s=(s-1)&curr){
            if(!isValid(prev,s))continue;
            res = max(res,__builtin_popcount(s) + mst(s,index + 1));
        }
        return res;
    }
    int maxStudents(vector<vector<char>>& seats) {
        this->seats = seats;
        memset(dp,-1,sizeof(dp));
        // dp.resize(1<<8,vector<int>(8,-1));
        return mst(0,0);
    }
};