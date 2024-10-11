class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        set<int>avl;
        int n = times.size();
        for(int i = 0;i<n;i++){
            avl.insert(i);
        }
        // dept, chair
        multiset<array<int,2>>st;
        // all arrival times are
        int at = times[targetFriend][0];
        sort(times.begin(),times.end());
        for(int i = 0;i<n;i++){
            while(st.size() && (*st.begin())[0] <= times[i][0]){
                avl.insert((*st.begin())[1]);
                st.erase(st.begin());
            } 
            if(at == times[i][0]) return *avl.begin();
            st.insert({times[i][1],*avl.begin()});
            avl.erase(avl.begin());
        }
        return -1;
    }
};