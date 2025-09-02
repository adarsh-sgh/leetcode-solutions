class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int cnt = 0;
        sort(points.begin(), points.end(),[&](auto x,auto y){
            x[1] *= -1;
            y[1] *= -1;
            return x < y;
        });
       for(int i = 0;i < n;i++){
        for(int j = i+1;j<n;j++){
            auto a = points[i], b = points[j];
            if(a[1] < b[1] || a[0] > b[0]) continue;
            bool valid = true;
            for(int k = 0;k< n;k++){
                // check if points[k] falls bw a and b
                if(k==i||k==j)continue;
                if(points[k][0] >= a[0] && points[k][0] <= b[0] && points[k][1] <= a[1] && points[k][1] >= b[1]){
                    valid = false;
                    break;
                }
            }
            cnt+=valid;
        }
       } 
       return cnt;
    }
};