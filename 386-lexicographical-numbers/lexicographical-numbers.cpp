class Solution {
public:
    vector<int> lexicalOrder(int n) {
       vector<int>ans;
       for(int i = 1;i<=n;i++)ans.push_back(i);
       sort(ans.begin(),ans.end(),[&](int a,int b){
        string as  = to_string(a);
        string bs = to_string(b);
        return as < bs;
       });
       return ans;
    }
};