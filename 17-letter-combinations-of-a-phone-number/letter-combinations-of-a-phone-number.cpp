class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> helper = {""};
        vector<string> ans;
        vector<vector<char>> phone{
      {'a', 'b', 'c'},
      {'d', 'e', 'f'},
      {'g', 'h', 'i'},
      {'j', 'k', 'l'},
      {'m', 'n', 'o'},
      {'p', 'q', 'r', 's'},
      {'t', 'u', 'v'},
      {'w', 'x', 'y', 'z'},
  };

    for(int i =0; i < digits.size();i++){
        int index = digits[i] - '2';
           for(auto &&a:helper){
            for(auto &&it:phone[index]){
                ans.push_back(a+it);
            }
        }
        swap(ans,helper);
        ans.clear();
    }
    if(digits.size() == 0){
        return {};
    }
    return helper;
    
    }
};