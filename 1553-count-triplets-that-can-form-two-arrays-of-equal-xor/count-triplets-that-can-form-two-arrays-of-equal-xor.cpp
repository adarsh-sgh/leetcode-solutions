class Solution {
public:
    int countTriplets(vector<int>& arr) {
       // => if xor(i...j-1) = xor(j...k)
       // <=> xor(i...j-1) ^ xor(j...k) = 0
       // <=> pf[k + 1] - pf[i] = 0 note that this is independent of j
       // we can choose any j for given i and k 
       // if i... k are valid k - i + 1 valid answers are bw them
       int n = arr.size();
       vector<int>pf(n + 1);
       map<int,vector<int>>mp;
       int ans = 0;
       mp[0].push_back(-1);
       for(int i = 0;i<n;i++){
          pf[i+1] = pf[i] ^ arr[i];
        //   ans += mp[pf[i+1]];
         for(auto &x:mp[pf[i+1]]){
            ans += i - x - 1;
         }
        //   if(pf[i+1] == 0)
        //   mp[pf[i+1]]++;
        mp[pf[i+1]].push_back(i);
       }
       for(auto &x:pf) cout<<x<<' ';

       return ans;
    }
};