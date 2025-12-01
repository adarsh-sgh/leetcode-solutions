class Solution {
public:
    int canRun(long long m, int n, vector<int>&batteries){
        long long usablePower = 0;
        for(auto &b:batteries){
            usablePower += min(1ll * b, m);
            if(usablePower >= m * n) return true;
        }
        return false;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
       // m minutes run kar sakta hai
       // [true, true, true, false, false , false]
       long long l = 0, r = 1e14;
       while(l < r){
        long long m = (l + r + 1) /2;
        if(canRun(m, n, batteries)){
            l = m;
        }else{
            r = m - 1;
        }
       }
       return l;
    }
};