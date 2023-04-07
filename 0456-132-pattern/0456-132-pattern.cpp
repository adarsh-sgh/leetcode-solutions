class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int mn =  INT_MAX, mx = INT_MIN;
        vector<int> st;
        // decreasing mono stack
        int k ;
        for(int i = nums.size() -1;i>=0;i--){
            auto x = nums[i];
            if(st.empty()){ 
            st.push_back(x);
            continue;
            }
            if(st.back() >= x) st.push_back(x);
            else {
                while(!st.empty() && st.back() < x){
                    k = st.back();
                    st.pop_back();
                }
                st.push_back(x);
            }
            if(x < k) return true;
        }
        return false;
    }
};