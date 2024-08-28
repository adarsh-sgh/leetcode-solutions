class Solution {
public:
    int countPairs(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                string s1 = to_string(nums[i]), s2 = to_string(nums[j]);
                // int diff = 0;
                if (s1.size() > s2.size())
                    swap(s1, s2);
                while (s2.size() > s1.size())
                    s1 = "0" + s1;
                int diff = 0;
                vector<int> mp(10);
                for (int i = 0; i < s1.size(); i++) {
                    diff += (s1[i] != s2[i]);
                    mp[s1[i] - '0']++;
                    mp[s2[i] - '0']--;
                }
                cout<<diff<<" "<<s1<<" "<<s2<<endl;
                bool allZero = true;
                for(auto &x:mp){
                    if(x) allZero = false;
                }
                if (diff <= 2 && allZero)ans++;
            }
        }
        return ans;
    };
};