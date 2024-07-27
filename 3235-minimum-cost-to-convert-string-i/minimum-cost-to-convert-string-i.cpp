class Solution {
public:
    int inf = 1e9 + 5;
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
       vector<vector<int>>g(26,vector<int>(26,inf)); 
       for(int i = 0;i<original.size();i++){
        int x = original[i] - 'a';
        int y = changed[i] - 'a';
        g[x][y] = min(g[x][y], cost[i]);
       }

     for(int k = 0;k<26;k++){
        
       for(int i = 0;i<26;i++){
            for(int j = 0;j<26;j++){
                g[j][j] = 0;
                g[i][j] = min(g[i][j], g[i][k]+ g[k][j]);
            }
        }
       }
        long long ans = 0; 
       for(int i = 0;i < source.size();i++){
            int x = source[i]-'a', y = target[i] - 'a';
            ans += g[x][y];
            if(g[x][y] > 1e9) return -1;
            // if(ans >= 1e9) return -1;
       }
       return ans;
    }
};