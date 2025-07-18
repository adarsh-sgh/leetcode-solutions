class Solution {
public:

    bool canFinish(int speed, vector<int>&piles, int h){
        int hourPassed = 0;
        for(auto &p:piles){
            // ceil
            hourPassed += (p + speed - 1)/speed;
            if(hourPassed > h) return false;
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 1e9;
        while(l < r){
            int m = (l + r)>>1;
            if(canFinish(m, piles, h)){
                r = m;
            }else{
                l = m + 1;
            }
        }
        return l;
    }
};