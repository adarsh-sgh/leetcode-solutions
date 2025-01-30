class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
       sort(heaters.begin(), heaters.end());
       int r = 0;
       for(int i = 0;i< houses.size();i++){
         auto hei = lower_bound(heaters.begin(), heaters.end(), houses[i]) - heaters.begin();
         int rc = INT_MAX;
         if(hei < heaters.size()) rc = heaters[hei] - houses[i];
         if(hei > 0)rc = min(rc, houses[i] - heaters[hei-1]);
         r = max(r, rc);
       } 
       return r;
    }
};