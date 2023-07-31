class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size() % k) return false;
        int groups = nums.size() / k;
        map<int,int>m;
        for(auto &&x:nums) m[x]++;
        while(groups--){
            auto el = m.begin()->first;
            for(int i = 0;i<k;i++)
            {
            if(!m.count(el))return false;
            else if(!--m[el])m.erase(el);
            el++;
            }
        }
        return true;
        
    }
};