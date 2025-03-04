class Solution {
public:
    bool checkPowersOfThree(int n) {
       vector<int>p;
       while(n > 0){
        int x = 0;
        int num = 1;
        while(num*3 <= n){
            num = num * 3;
            x++;
        }
        // x => highest pow of 3 we can cut out of n
        n -= num;
        p.push_back(x);
       } 
       set<int>s(p.begin(), p.end());
        return s.size() == p.size();
    }
};