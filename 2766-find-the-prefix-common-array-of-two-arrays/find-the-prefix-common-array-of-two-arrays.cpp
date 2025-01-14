class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
       vector<int>ans(n + 1); 
       set<int>a,b;
       for(int i = 0;i<n;i++){
        int curr = 0;
        if(A[i] == B[i]){
            curr = 1;
        }else{
            curr = a.count(B[i]) + b.count(A[i]);
        }
        ans[i + 1] = ans[i] + curr;
        a.insert(A[i]);
        b.insert(B[i]);
       }
       ans.erase(ans.begin());
       return ans;
    }
};