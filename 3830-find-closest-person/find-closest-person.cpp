class Solution {
public:
    int findClosest(int x, int y, int z) {
       int od = abs(z-x), td = abs(y-z);
       if(od == td)return 0;
       if(od < td) return 1;
       return 2; 
    }
};