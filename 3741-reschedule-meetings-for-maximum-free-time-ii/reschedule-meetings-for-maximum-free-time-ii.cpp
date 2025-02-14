class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
       // go through each meeting
       // see if this fits in the biggest hole
       // if it's adjacent to biggest hole see if it fits in second/third biggest hole 
       
       // hole size, list<index before hole>
       map<int,vector<int>>mp;
       int n = startTime.size();
       mp[startTime[0]].push_back(-1);
       for(int i = 1;i< n;i++){
         int hole = startTime[i] - endTime[i-1];
         mp[hole].push_back(i-1);
       }
       mp[eventTime - endTime.back()].push_back(n-1);
       // 3 biggest holes
       // index, hole size
       vector<array<int,2>>hl;
       for(auto &&it = mp.rbegin();it != mp.rend();it++){
           auto &&x = it ->first;
           for(auto &&y:it->second){
            hl.push_back({x,y});
            if(hl.size() == 3){
                it = mp.rend();
                break;
            }
           }
        }
       int ans = 0;
       for(int i = 0;i< n;i++){
        // space on both sides of meeting
        int sip1 = i + 1 < n ? startTime[i+1] : eventTime;
        int et1 = i - 1 >= 0 ? endTime[i-1]: 0;
        ans = max(ans, sip1 - et1 -( endTime[i] - startTime[i]));
        // move ith meeting to some non adjacent hole
        for(auto &[x,y]:hl){
            if(y == i || y == i-1)continue;
            if(x < endTime[i] - startTime[i])break;
            ans = max(ans, sip1 - et1);
            break;
        }
       }
       return ans;
       
    }
};