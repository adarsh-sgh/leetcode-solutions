class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        //bricks used
      multiset<int>bu;
      for(int i =1;i<heights.size();i++){
          int reqb = heights[i] - heights[i-1];
          if(reqb < 0)continue;
          if(bricks < reqb && ladders <= 0){
              return i-1;
          }
          if(bricks >= reqb){
              bricks -= reqb;
              bu.insert(reqb);
          }else{
          //else give up ladder to get bricks
            ladders --;
            //brought bricks
            if(bu.empty()) continue;
            int bb = *bu.rbegin();
            if(bb < reqb) continue;
            bricks += bb - reqb;
            // if(bricks < 0) return
            bu.erase(prev(bu.end()));
            bu.insert(reqb);
          }

      }
      return heights.size() - 1;
    }
};