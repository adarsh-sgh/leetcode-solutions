class Solution {
public:
    double area(int x1, int y1, int x2, int y2, int x3, int y3){
        return 0.5*abs(x1* (y2 - y3) - x2*(y1 - y3) + x3 * (y1-y2));
    }
    double largestTriangleArea(vector<vector<int>>& p) {
        int n = p.size();
        double ans = 0;
       for(int i = 0;i< n;i++){
        for(int j = i+1;j < n;j++){
            for(int k = j + 1;k<n;k++){
                auto p1 = p[i], p2 = p[j], p3 = p[k];
                auto a = area(p1[0], p1[1],p2[0], p2[1], p3[0], p3[1]);
                ans = max(ans, a);
            }
        }
       } 
       return ans;
    }
};