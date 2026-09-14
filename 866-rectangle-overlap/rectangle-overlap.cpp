class Solution {
public:

    bool isBetween(int x1, int x2, int y1, int y2, int xc, int yc){
        return xc > x1 && xc < x2 && yc > y1 && yc < y2;
    }

    bool isRectangleOverlap1(vector<int>& rec1, vector<int>& rec2) {
       int  x1 = rec1[0], y1 = rec1[1], x2 = rec1[2], y2 = rec1[3];
       // x1, y2 to x2, y1 ke beech mein koi bhi corner hai rec2 ka ? 
        return isBetween(x1,x2,y1,y2, rec2[0], rec2[1]) 
       || isBetween(x1,x2,y1,y2, rec2[0], rec2[3])
        || isBetween(x1,x2,y1, y2, rec2[2], rec2[1])
        || isBetween(x1,x2,y1,y2, rec2[2], rec2[3]);
    }

    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // bottom left corner 
        int xmax = max(rec1[0], rec2[0]);
        int ymax = max(rec1[1], rec2[1]);

        // top right
        int xmin = min(rec1[2], rec2[2]);
        int ymin = min(rec1.back(), rec2.back());
        // cout<<xmax<<" "<<ymax<<' '<<xmin<<' '<<ymin;
        return xmax < xmin && ymax < ymin;
    }



};

// 7, 13 -> 10
// 8, 15 -> 8