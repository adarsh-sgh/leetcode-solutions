class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
       auto good = [&](int c){
          int cnt = 0;
          int curr = 0;
          for(auto &w:weights){
            if(curr + w > c){
                curr = 0;
                cnt++;
            }
            curr += w; 
          }
          if(curr){
            cnt++;
          }
          return cnt <= days;
       }; 
       int l = *max_element(weights.begin(),weights.end());
       int r = accumulate(weights.begin(), weights.end(),0ll);
       while(l < r){
         int m = (l + r)>> 1;
         if(good(m)){
            r = m;
         }else{
            l = m + 1;
         }
       }
       return l;
    }
};