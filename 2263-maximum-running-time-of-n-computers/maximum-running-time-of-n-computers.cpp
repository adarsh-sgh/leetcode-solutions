class Solution {
public:

    bool canRun(long long time,int n,vector<int>&b){
        long long reqp = time * n;
        long long hasp = 0;
        for(int i = 0;i<b.size();i++){
            hasp += min(1ll * b[i],time);
            if(hasp >= reqp) return true;
        }
        return false;
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        typedef long long int;
        long long l = 0, r = 1e15/n;
        while(l<r){
            long long mid = (l+r + 1)/2;
            if(canRun(mid,n,batteries)){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        return l;
    }
};