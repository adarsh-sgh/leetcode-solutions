class Solution {
public:
    vector<int>v;
    // bool turnofa = true;
    bool awins(int l,int r,int asum,int bsum,bool turnofa){
        if(l > r) return asum >= bsum;
        if(turnofa){
            // turnofa = false;
            return awins(l+1,r,asum+v[l],bsum,!turnofa)||awins(l,r-1,asum+v[r],bsum,!turnofa);
        }else{
            // turnofa = true;
             return awins(l+1,r,asum,bsum+v[l],!turnofa) && awins(l,r-1,asum,bsum+v[r],!turnofa);
        }
        // turnofa = ~turnofa;
        return false;
    }
    bool PredictTheWinner(vector<int>& nums) {
        v = nums;
        return awins(0,v.size() -1,0,0,true);
    }
};