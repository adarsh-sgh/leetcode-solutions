class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int n = points.size();
        long long ans = INT_MAX;
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                int x1 = points[i][0], y1 = points[i][1],
                x2 = points[j][0], y2 = points[j][1];
                if(x1==x2||y1==y2)continue;
                auto it = lower_bound(points.begin()+i+1,points.end(),vector<int>{x1,y2});
                if(it==points.end() || *it != vector<int>{x1,y2} ) continue;
                it = lower_bound(points.begin()+i+1,points.end(),vector<int>{x2,y1});
                if(it==points.end() || *it != vector<int>{x2,y1} ) continue;
                ans = min(ans,1ll*abs((x2 - x1) *( y2 - y1)));
            }
        }
        if(ans >= INT_MAX) return 0;
        return ans;
    }
};