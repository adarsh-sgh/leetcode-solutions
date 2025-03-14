class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
       // binary search ?
       auto good = [&](int x){
        // give x candy to each children
        if(x == 0) return true;
        long long piles = 0;
        for(auto &c:candies){
            piles += c / x;
            if(piles >= k) return true;
        }
        return piles >= k;
       };
       int l = 0, r = *max_element(candies.begin(), candies.end());
       while(l < r){
        int m = (l + r + 1) >> 1;
        if(good(m)){
           l = m; 
        }else{
            r = m - 1;
        }
       }
       return l;
    }
};