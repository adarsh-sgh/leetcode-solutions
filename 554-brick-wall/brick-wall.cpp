class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
      map<int,int>m;
      int mx = 0;
      for(auto &&w:wall){
        int sum = 0;
        for(int i = 0;i< w.size() - 1;i++){
            sum+=w[i];
            m[sum]++;
            mx = max(mx,m[sum]);
        }
      }
      return wall.size() - mx;  
    }
};