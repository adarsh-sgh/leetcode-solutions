class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        // fix sized window of len k 
        // if there're wc counts of W in this window, ans = min(wc)
        int ans = k;
        int wc = 0;
        for(int i = 0;i < blocks.size();i++){
            wc += blocks[i] == 'W';
            if(i - k >= 0){
                wc -= blocks[i-k] == 'W';
            }
            if(i >= k-1){
                ans = min(ans, wc);
            }
        }
        return ans;
    }
};