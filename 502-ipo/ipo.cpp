class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<array<int,2>>v(profits.size());
        for(int i = 0;i<profits.size();i++) v[i] = {capital[i],profits[i]};
        sort(v.begin(),v.end());
        priority_queue<int>gains;
        int maxw = w;
        
        int n = v.size();
        int i = 0;
        while(k--){
            while( i < n && v[i][0] <= w)gains.push(v[i++][1]);
            if(gains.empty())break;
            w += gains.top();
            gains.pop();
        }
        return w;
    }
};