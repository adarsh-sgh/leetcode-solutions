class Solution {
public:
// old submission
    int maxTwoEvents(vector<vector<int>>& events) {
       // sort by end and start times 
       vector<vector<int>>vc = events;
       sort(events.begin(),events.end(), [&](auto &a, auto &b) {
        return a[1] < b[1];
       });
       sort(vc.begin(),vc.end());
       // max val of an interval with start > x, this start will keep dec. 
       int j = vc.size() - 1;
       int n = vc.size();
       int ans = 0;
       int mx = 0;
        for(int i = n - 1;i>=0;i--){
            int e = events[i][1];
            while(j >= 0 && vc[j][0] > e){
                mx = max(mx, vc[j][2]);
                j--;
                };
            ans = max(ans, mx + events[i][2]);
        }
        return ans;
    }
};