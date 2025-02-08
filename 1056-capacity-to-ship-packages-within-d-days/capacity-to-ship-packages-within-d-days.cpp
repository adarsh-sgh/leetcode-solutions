class Solution {
public:
    // ans min = 10, max = 55
    // []
    int d;
    bool good(vector<int>&weights, int  weightLimit){
       // arr [no, no , no ,no ..... no, yes, yes....yes] 

       // find index of first yes
       // 10 -> no
       // 11 -> no ....  
       //   55  -> yes
       int days = 1;
       int curr = 0;
       for(auto &w:weights){
        if(curr + w > weightLimit){
            days++;
            curr = 0;
        }
        curr += w; 
       }
       return days <= d;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        d = days;
        int l  = 0, r = 0;
        for(auto &w:weights){
            r += w;
            l = max(w, l);
        }

        while(l < r){
            int m = (l + r) / 2;
            if(good(weights,m)){
                r = m;
            }else{
                l = m + 1;
            }
        }
        return l;
    }
};