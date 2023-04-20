class Solution {
public:

     vector<int> v;
    void inr(int &i){
        int io = i;
        while(i < v.size() && v[i] == v[io])i++;
    }
    void dec(int &i){
        int io = i;
        while(i >= 0 && v[i] == v[io])i--;
    }
    vector<vector<int>>twoSum(int i,int j,long long target){
        vector<vector<int>>ans;
        while(i < j){
            if(v[i] + v[j] < target){
                inr(i);
            }else if (v[i] + v[j] > target){
                dec(j);
            }else{
                ans.push_back({v[i],v[j]});
                inr(i);
                dec(j);
            }
        }
        return ans;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int a = 0, b = n-1;
        v = nums;
        vector<vector<int>>ans;
       for(int a = 0;a<n;inr(a)){
           for(int b = n-1;b >= a+3;dec(b)){
               int sum = nums[a] + nums[b];
               long long targetNew = 0ll + target - sum;
               vector<vector<int>>ts = twoSum(a+1,b-1,targetNew);
                for(auto &&x:ts){
                    x.push_back(nums[a]);
                    x.push_back(nums[b]);
                    ans.push_back(x);
                }
           }
       }
       return ans;
    }
};