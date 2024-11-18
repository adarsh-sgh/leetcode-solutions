class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
       vector<int>ans;
       int n = code.size();
       int ko = k;
       if(k < 0) k = -1;
       else if(k > 0)k = 1;

       for(int i = 0;i<n;i++){
        int curr = 0;
        if(k == 0){
            ans.push_back(0);
            continue;
        }
        for(int d = 1;d<=abs(ko);d++){
            curr += code[(i + d * k + 2 * n) % n];
        }
        ans.push_back(curr);
       } 
       return ans;
    }
};