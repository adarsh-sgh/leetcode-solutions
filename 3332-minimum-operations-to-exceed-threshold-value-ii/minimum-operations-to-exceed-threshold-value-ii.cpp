class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
       multiset<int>se(nums.begin(), nums.end());
       int ans = 0;
        while(*se.begin() < k){
            int it = *se.begin();
            se.erase(se.begin());
            int it2 = *se.begin();
            se.erase(se.begin());
            if(it < it2) swap(it,it2);
            int toPut;
            if(it + 2ll * it2 > 1e9 ) toPut = INT_MAX;
            else toPut = it + (2 * it2);
            se.insert(toPut);
            cout<<toPut<< ' '<<it<<' '<<it2<<endl;
            ans++;
        } 
        return ans;
    }
};