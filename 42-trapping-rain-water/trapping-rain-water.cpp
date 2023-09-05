class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int maxl = 0, maxr = 0;
        int trapped = 0;
        while(l <= r){
            if(height[l] < height[r]){
                trapped += max(0, maxl - height[l]);
                maxl = max(maxl,height[l]);
                l++;
            }else{
                trapped += max(0, maxr - height[r]);
                maxr = max(maxr,height[r]);
                r--;
            }
        }
        return trapped;
    }
};