class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<vector<double>>v;
        for(int i = 0;i<wage.size();i++){
            v.push_back({(double)wage[i]/quality[i],(double)quality[i]});
        }
        sort(v.begin(),v.end());
        priority_queue<int>q;
        double qsum = 0;
        double ans = 1e9;
        for(int i = 0;i<v.size();i++){
            if(q.size()==k){
                qsum -= q.top();
                q.pop();
            }
            qsum += v[i][1];
            q.push(v[i][1]);
            if(q.size()==k){
                ans = min(ans,qsum * v[i][0]);
            }
        }
        return ans;
    }
};