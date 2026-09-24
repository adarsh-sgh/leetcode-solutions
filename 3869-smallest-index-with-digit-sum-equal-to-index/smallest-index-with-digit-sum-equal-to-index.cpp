class Solution {
public:
    int sod(int x){
        int sum = 0;
        while(x){
            sum += x % 10;
            x/=10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
       for(int i = 0;i < nums.size();i++){
        int x = nums[i];
        if(sod(x) == i) return i;
       }
       return -1;
    }
};