class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
       int sum = accumulate(nums.begin(), nums.end(), 0ll);
       int target = sum - x;
       map<int,int>mp;
       int rsum = 0;
       int maxl = -1;
       for(int i = 0; i < nums.size();i++){
        rsum+= nums[i];
        mp[0] = -1;
        if(mp.count(rsum - target)){
            int l = i - mp[rsum-target];
            maxl = max(l, maxl);
        }
        if(!mp.count(rsum)){
            mp[rsum] = i;
        }
       }
    //    cout<<target<<' '<<maxl;
    if(sum==x) return nums.size();
       if(maxl == -1) return -1;
       return nums.size() - maxl;
    }
};

// let ts = total sum
// we want to find longest subarray with sum = ts - x say length = l
// nums.size() - l is the answer

// 11-5= 6