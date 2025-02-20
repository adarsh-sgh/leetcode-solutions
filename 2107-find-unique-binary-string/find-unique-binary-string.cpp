class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
       int n = nums[0].size();
       set<int>se;
       for(auto &x:nums){
        int curr = 0;
        for(int i = 0;i < n;i++){
            if(x[n - i - 1] == '1'){
                curr = curr  | (1 << i);
            }
        }
        se.insert(curr);
       }

       for(int i = 0;i < (1<<n);i++){
           if(!se.count(i)){
             string is;
             for(int j = n-1;j >= 0;j--){
                if(i >> j & 1)is+='1';
                else is += '0';
             }
             return is;
           }
       } 
       return "";
    }
};