class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size()/3;
        sort(piles.begin(),piles.end());
        int mc = 0;
        for(int i = piles.size()-2;i>=n;i-=2){
            mc += piles[i];
        }
        return mc;
    }
};