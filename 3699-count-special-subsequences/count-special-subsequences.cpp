class Solution {
public:
    long long numberOfSubsequences(vector<int>& nums) {
       // p * r = q * s 
       // p / q =  s / r
       int n = nums.size();
       map<long long,map<long long,long long>>mp;
       long long ans = 0;
       for(int r = 0;r < n;r++){
        // q = r - 2 is not in mp rest all are 
        int q = r - 2;
        for(int p = q - 2;p>=0;p--){
            int np = nums[p], nq = nums[q];
            int nr = np / gcd(np,nq);
            int dr = nq/gcd(np,nq);
            mp[nr][dr]++;
        }
        for(int s = r + 2;s < n;s++){
            // s/r
            int ns = nums[s], nrr = nums[r];
            int nr = ns/ gcd(ns,nrr);
            int dr = nrr / gcd(ns,nrr);
            ans += mp[nr][dr];
        }
       }
      return ans;
    }
};