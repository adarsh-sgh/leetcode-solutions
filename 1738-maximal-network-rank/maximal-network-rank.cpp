class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>adj[n+1];

        for(auto it:roads){
            // cout<<it<<"=> ";
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        cout<<"\n";
        int cnt=0;
        int mx = INT_MIN;
        int f1=0, f2=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int f = i;
                int s = j;
                if(f==s){
                    continue;
                }
                cout<<f<<","<<s<<"->";
                for(auto i: adj[f]){
                    // cout<<i<<"  ";
                    if(i!=s){
                        cnt++;
                    }
                }
                for(auto i: adj[s]){
                    if(i!=f){
                        cnt++;
                    }
                }
                for(auto i:adj[f]){
                    if(i==s){
                        cnt++;
                        break;
                    }
                }
                cout<<cnt<<endl;
                if(cnt>mx){
                    f1 = i;
                    f2 = j;
                    mx = max(mx, cnt);
                }
                cnt=0;
            }
        }
       
        return mx;
    }
};