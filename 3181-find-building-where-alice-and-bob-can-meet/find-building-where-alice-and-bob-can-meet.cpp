class Solution {
public:
# define dbg(...) 42;
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
           // assume ai < bi
       // first el on right of bi > max(h[ai], h[bi])

       // sort all queries by bi (right side element)
      for(auto &q:queries) sort(q.begin(), q.end());
      for(int i = 0;i < queries.size();i++){
        queries[i].push_back(i);
      }
      sort(queries.begin(),queries.end(), [&](auto &x, auto &y){
        return x[1] < y[1];
      });
      int hi = heights.size() - 1;
      // scanned ele. should be MI. 
      // if storing in reverse can make them MD. or use a deque if against storing in reverse
      // going through reverse strategy
      // array looks like 9 8 5 4
      // indices ->       6 4 2 1
      // find last element >= max(ha, hb) since that will have least index, bs in ttt..fff.. array
      
      vector<int>scanned;
      // find last element in scanned with val > hmin
       auto bs = [&](int hmin){
        int l = 0, r = scanned.size() - 1;
        while(l < r){
            int m = (l + r + 1)>>1;
            if(heights[scanned[m]] > hmin){
                l = m;
            }else{
                r = m - 1;
            }
        }
        return l;
      };
      vector<int>ans;
      for(int i = queries.size() - 1;i>=0;i--){
        auto ai = queries[i][0], bi = queries[i][1];
        // bi and baad ke elements daal do
        while(hi >= bi){
           // put hi into scanned 
            while(scanned.size() && heights[scanned.back()] <= heights[hi]){
                scanned.pop_back();
            }
            scanned.push_back(hi);
            hi--;
        }
        if(heights[bi] > heights[ai] || ai == bi){
            queries[i].push_back(bi);
            continue;
        }
        // find last element >= max(ha, hb) since that will have least index, bs in ttt..fff.. array
        int ansi = bs(max(heights[ai], heights[bi]));
        // dbg(ai,bi,ansi,scanned);
        if(heights[scanned[ansi]] <= max(heights[ai], heights[bi])){
            queries[i].push_back(-1);
        }else{
            queries[i].push_back(scanned[ansi]);
        }
      }

      sort(queries.begin(),queries.end(), [&](auto &x, auto &y){
        return x[2] < y[2];
      });
      for(auto &q:queries){
        ans.push_back(q[3]);
      }
     return ans;
    }
};