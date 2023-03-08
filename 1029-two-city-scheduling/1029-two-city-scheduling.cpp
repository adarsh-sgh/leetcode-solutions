class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(),costs.end(),[this](auto a,auto b){
            return a[0] - a[1] > b[0] - b[1]; 
        });
        int cost = 0;
        for(int i = 0;i<costs.size()/2;i++){
            cost += costs[i][1];
            cost += costs[costs.size()/2+i][0];
        }
        return cost;
    }
};