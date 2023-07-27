class Solution {
public:
    int atmost(vector<int>&v,int k){
        int j = 0, oc = 0;
        int n = v.size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            oc += v[i] & 1;
            while(oc > k){
                oc-=v[j] & 1;
                j++;
            }
        ans += i - j + 1;
        }
        return ans;

    }
    int numberOfSubarrays(vector<int>& A, int k) {
  return atmost(A,k) - atmost(A,k-1);
}
        
};