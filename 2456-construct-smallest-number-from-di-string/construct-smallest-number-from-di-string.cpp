class Solution {
public:
    string smallestNumber(string pattern) {
       int n = pattern.size() + 1;
       string s;
       for(int i = 0; i < n;i++){
        s += i + '1';
       }
       do{
        // is s valid
        bool isValid = true;
        for(int i = 0;i < n - 1;i++){
            if((s[i+1] > s[i]) ^ (pattern[i] == 'I')){
               isValid = false;
               break; 
            }
        }
        if(isValid)return s;
       }while(next_permutation(s.begin(), s.end()));
       return "";
    } 
};