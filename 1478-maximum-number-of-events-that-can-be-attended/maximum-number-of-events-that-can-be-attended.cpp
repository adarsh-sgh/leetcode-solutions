class Solution {
public:
    static bool cmp(vector<int>v1, vector<int> v2){
        if(v1[1]==v2[1])return v1[0] < v2[0];
        return v1[1] < v2[1];
    }

    int maxEvents(vector<vector<int>>& events) {
        
        sort(events.begin(),events.end());
        int ans = 0 ; int ph = 1;
          priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

        int i = 0;
        while(i<events.size()||q.size()){
            for(;i<events.size() && events[i][0] <= ph;i++){
                q.push({events[i][1],events[i][0]});
            }
            if(q.empty()){
                q.push({events[i][1],events[i][0]});
                i++;
            }
            auto t = q.top();
            if(t.first >= ph){
            ph = max(ph,t.second) + 1;
            ans++;
            }
            q.pop();
        }
        // for(auto &&it:events){
        //     if(it[1] >= ph) {
        //         ph = max(ph,it[0])+1;
        //         ans++;
        //     }
        // }

        return ans;
    }

};