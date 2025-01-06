class Solution {
public:
    vector<int> minOperations(string boxes) {
       // ans[i] = sum((j - i) * boxes[j])
       int n = boxes.size();
       // sum, cnt
       vector<array<long long,2>>pf(n+1);
       for(int i = 0;i<n;i++){
        bool x = boxes[i] == '1';
        pf[i+1] = {pf[i][0] + x*i, pf[i][1] + x};
       }

       vector<int>ans(n);
       for(int i = 0;i < n;i++){
         auto [sp, cp] = pf[i];
         auto ss = pf.back()[0] - sp;
         auto cs = pf.back()[1] - cp;
         ans[i] = abs(sp - cp * i) + abs(ss - cs * i);
       }
       return ans;
      
    }

};