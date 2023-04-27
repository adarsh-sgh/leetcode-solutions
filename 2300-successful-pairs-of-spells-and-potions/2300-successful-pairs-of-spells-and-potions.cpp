class Solution {
public:

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>ans(spells.size());
        sort(potions.begin(),potions.end());
        for(int i = 0;i<spells.size();i++){
            long long s = spells[i];
            int pn = potions.size();
            int l = 0, r = pn - 1;
            while(l<r){
                int mid = (l + r) / 2;
                if(s * potions[mid] >= success){
                    r = mid;
                }else{
                    l = mid + 1;
                }
            }
            if(s * potions[l] < success)continue;
            ans[i] = potions.size() - l;
        }
        return ans;
    }
};