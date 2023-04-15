class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int>yr(101);
        for(auto &&x:logs){
            int b = x[0], d = x[1];
            b-=1950;d-=1950;
            yr[b]++;
            yr[d]--;
        }
        int maxLive = 0;
        int living = 0;
        int mxyr = -1;
          for(int i =0;i<101;i++){
                living = living + yr[i];
                if(maxLive < living){
                    maxLive = living;
                    mxyr = i + 1950;
                }
            }
            return mxyr;
    }
};