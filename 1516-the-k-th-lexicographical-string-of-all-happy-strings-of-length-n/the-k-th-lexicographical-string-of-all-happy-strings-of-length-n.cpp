class Solution {
public:
    string abc = "abc";
    set<string>se;
    void fill(string&s, int n){
        if(n == 0){
            se.insert(s);
            return;
        }
       for(auto &c:abc){
        if(s.size() && s.back()==c)continue;
         s +=c;
         fill(s, n-1);
         s.pop_back();
       } 
    }
    string getHappyString(int n, int k) {
       string s;
       fill(s, n); 
        auto it = se.begin();
        if(se.size() < k) return "";
        while(--k)it++;
        return *it;
    }
};