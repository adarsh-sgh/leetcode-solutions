class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
       // gandh element -> element with same parity as next element
       // if smallest gandh element >= q[i][0] is >= q[i][1] ans = true
       vector<int>gandh;
       for(int i = 0;i< nums.size() - 1;i++){
        if(~(nums[i] ^ nums[i+1]) & 1){
            gandh.push_back(i);
        }
       } 
        for(auto &x:gandh) cout<<x<<' ';
        cout<<'\n';
       vector<bool>ans;
       for(auto &q:queries){
            int gg = lower_bound(gandh.begin(),gandh.end(), q[0]) - gandh.begin();
            cout<<gg;
            ans.push_back(gg >= gandh.size() || gandh[gg] >= q[1]);
       }
       return ans;
    }
};