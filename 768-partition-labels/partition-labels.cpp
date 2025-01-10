class Solution {
public:

    vector<int> partitionLabels(string s) {
        vector<int>ans;
        int l = 0;
        vector<int>maxInd(26);
        for(int i = 0;i< s.size();i++){
            maxInd[s[i] - 'a'] = i;
        }
       int goUpto = 0;
       for(int i = 0;i< s.size();i++){
        l++;
        goUpto = max(goUpto, maxInd[s[i] - 'a']);
        if(i == goUpto){
            ans.push_back(l);
            l = 0;
        }
       } 
       return ans;
    }
};