class Solution {
public:
   static bool cmp(string a, string b){
    return a+b<b+a;
}

  string largestNumber(vector<int>& nums) {
        vector<string> s(nums.size());
        for(int i =0;i<nums.size();i++){
          s[i] = to_string(nums[i]);
        }
        sort(s.begin(),s.end(),cmp);
        string ans;
        for(int i = s.size()-1;i>=0;i--){
          ans+=s[i];
        }
      if(ans[0]=='0')
          return "0";
      return ans;
    }
};