class Solution {
public:
    bool rotateString(string s, string goal) {
       if(s.size() != goal.size())return false;
       int n = s.size();
       for(int i = 0;i < s.size();i++){
        // i is the starting index for s
        bool match = true;
        for(int j = 0;j < s.size();j++){
           if(s[(i + j) % n] != goal[j]){
            match = false;
            break;
           }
        }
        if(match) return true;
       } 
       return false;
    }
};