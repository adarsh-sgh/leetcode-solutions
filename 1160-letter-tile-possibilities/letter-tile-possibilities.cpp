class Solution {
public:
    int numTilePossibilities(string tiles) {
        // n = 7, n! = 5040, 2^n = 128 
        set<string> se;
        int n = tiles.size();
        for(int bm = 1;bm < (1<<n);bm++){
           string s;
           for(int i = 0;i < n;i++){
            if(bm >> i & 1)s+=tiles[i];
           } 
          if(se.count(s))continue;
          sort(s.begin(), s.end());
          do{
            se.insert(s);
          }while(next_permutation(s.begin(), s.end()));
        }
        return se.size();
    }
};