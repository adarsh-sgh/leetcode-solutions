class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
       map<int,int>cb;// count of balls on this color
       map<int,int>bc;// color of ball b
       vector<int>ans;
       int cols = 0;
       for(auto &q:queries){
            cb[q[1]]++;
            if(bc.count(q[0]) && --cb[bc[q[0]]] == 0){
                cb.erase(bc[q[0]]);
            }
            bc[q[0]] = q[1];
            ans.push_back(cb.size());
       }
       return ans;
    }
};