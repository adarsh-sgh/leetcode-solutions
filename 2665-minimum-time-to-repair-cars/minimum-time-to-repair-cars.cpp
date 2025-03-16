class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        auto yess = [](long long r, long long t,long long n){
            return t >= r * n * n;
        };
        auto good = [&](long long t){
            long long rep = 0;
            for(auto &r:ranks){
                // r * n^2 = t
                // n = sqrt(t/r)
               long long curr = sqrt(t/r);
            //    if(yess(r,t,curr-1)){
            //     curr--;
            //    }else if(yess(r,t,curr+1)){
            //     curr++;
            //    }
               rep += curr;
               if(rep >= cars) return true;
            }
            return false;
        };
        long long l = 0, r = 1e18;
        while(l < r){
            long long m = (l + r)/2;
            if(good(m)){
               r = m; 
            }else{
                l = m + 1;
            }
        }
        return l;
    }
};