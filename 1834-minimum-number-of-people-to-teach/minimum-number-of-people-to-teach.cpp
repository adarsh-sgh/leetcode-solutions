class Solution {
public:
 // graph h most
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        vector<vector<int>>fs;
        vector<set<int>>lset;
        for(auto &l:languages){
            lset.push_back(set<int>(l.begin(), l.end()));
        }
        for(auto &f:friendships){
            // if f is not good put in fs
            int f0 = f[0] - 1, f1 = f[1] - 1;
            auto l0 = lset[f0];
            bool good = false;
            for(auto &x:lset[f1]){
                if(l0.count(x)){
                    good = true;
                    break;
                }
            }
            if(good)continue;
            fs.push_back(f);
        }
        int ans = 1e8;
        for(auto &x:fs){
            cout<<x[0]<<' '<<x[1]<<endl;
        }
        cout<<endl;
       for(int l = 1;l<=n;l++){
        int curr = 0;
        for(auto&f:fs){
            int f1 = f[0], f2 = f[1];
            if(!lset[f1 - 1].count(l)){
                lset[f1-1].insert(l);
                curr++;
            }
             if(!lset[f2 - 1].count(l)){
                lset[f2-1].insert(l);
                curr++;
            }
        }
        ans = min(ans,curr);
       } 
       return ans;
    }
};