class Solution {
public:
    string stringHash(string s, int k) {
        string result = "";
        int sum = 0;
        for(int i = 0;i<s.size();i++){
            sum += s[i] - 'a';
            if(i % k == k-1){
                result += sum % 26 + 'a'; 
                sum = 0;
            }
        }
        // result += sum % 26 + 'a';
        return result;
    }
};