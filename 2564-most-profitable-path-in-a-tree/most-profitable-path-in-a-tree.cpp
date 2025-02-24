class Solution {
public:
//  node, time when bob visited it
    map<int,int>mp;
    vector<vector<int>>adj;
    vector<int>amt;
    int t = 0;
    bool dfs(int x, int p, int t){
        if(x == 0){
            mp[x] = t;
            return true;
        }

        bool res = false;
        for(auto &a:adj[x]){
            if(a == p)continue;
            res = res ||  dfs(a, x, t+1);
        }

        if(res){
            // cout<<res<<' '<<x<<' '<<t<<endl;
            mp[x] = t;
        }
        return res;
    }
    int inf = 1e9;
    int profit(int x,int p,int t){
        int curr = 0, res = -inf;
        bool virgin = true;
        if(!mp.count(x) ||  mp[x] > t){
            curr = amt[x];
        }else if(mp.count(x) && mp[x] == t){
            curr = amt[x]/2;
        }

        for(auto &a:adj[x]){
            if(a == p)continue;
            virgin = false;
            res = max(res, profit(a, x, t+1));
        }
        if(virgin) res = 0;
        // cout<<res + curr<< ' '<<x<<endl;
        return res + curr;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
       // there's a unique path bw any two nodes in a tree
       // bob's path is pre-defined
       // alice can choose any of the ending nodes then his path is also defined
       adj.resize(edges.size() + 1);
       amt = amount;
       for(auto &e:edges){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
       }
       dfs(bob, -1, 0);
       return profit(0,-1,0);
    }
};