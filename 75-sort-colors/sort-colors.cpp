class Solution {
public:
    void sortColors(vector<int>& nums) {
        array<int,3>v;
       for(auto &x:nums){
        v[x]++;
       }
       nums.clear();
        for(int i = 0;i < 3;i++){
            while(v[i]--){
                nums.push_back(i);
            }
        }
    }
};