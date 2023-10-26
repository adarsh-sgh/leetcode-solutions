class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        double tmax = -1;
        int ans = 0;
        vector<array<int,2>>v;
        for(int i = 0;i<n;i++){
            v.push_back({position[i],speed[i]});
        }
        sort(v.begin(),v.end());
        for(int i = n-1;i>=0;i--){
            double tc = (target - v[i][0]) * 1.0 / v[i][1];
            if(tmax < tc){
                ans++;
                tmax = tc;
            }
        }
        return ans;
    }
};