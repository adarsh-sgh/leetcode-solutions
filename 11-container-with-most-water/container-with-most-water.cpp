class Solution {
public:
    int maxArea(vector<int>& height) {
     int i = 0, j = height.size() - 1;
     int ans = 0;
     while(i < j){
        ans = max(ans, min(height[i], height[j]) * (j - i));
        // if i, j is not the optimal ans
        // then chote wale ko to for sure move karna padega
        // bade wale ko baad mein dekh lenge 
        if(height[i] < height[j]){
           i++;
        }else{
            j--;
        }
     } 
     return ans;
    }
};