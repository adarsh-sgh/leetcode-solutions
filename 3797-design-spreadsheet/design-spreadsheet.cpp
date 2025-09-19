class Spreadsheet {
public:
    vector<vector<int>>ss;
    Spreadsheet(int rows) {
       ss.resize(26,vector<int>(rows+1));
    }
    array<int,2> ij(string cell){
        int i = cell[0] - 'A';
        cell.erase(cell.begin());
        int j = stoi(cell);
        return {i,j};
    }
    void setCell(string cell, int value) {
        auto [i,j] = ij(cell);
        ss[i][j] = value;
    }
    
    void resetCell(string cell) {
        setCell(cell,0);
    }
    
    int value(string x){
        // cout<<x<<' ';
        if(x[0] >= 'A' && x[0] <= 'Z'){
            auto [i,j] = ij(x);
            return ss[i][j];
        }
        return stoi(x);
    }

    int getValue(string formula) {
       formula.erase(formula.begin());
        int i = formula.find("+");
        // cout<<i<<"i ";
        string x = formula.substr(0, i);
        string y = formula.substr(i+1, formula.size() - i - 1);
        return value(x) + value(y);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */