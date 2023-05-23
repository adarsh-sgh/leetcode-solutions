class Solution {
public:
    long long ceil(long long a, int b){
        if(a==0) return 0;
        return 1 + (a-1)/b;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int>ans(spells.size());
        for(int i = 0;i<spells.size();i++){
            long long minp = ceil(success,spells[i]);
            auto cnt = potions.end()-lower_bound(potions.begin(),potions.end(),minp);
            ans[i] = cnt;
        }
        return ans;
    }
};