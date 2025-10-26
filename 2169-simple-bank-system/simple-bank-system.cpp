class Bank {
public:
    vector<long long>b;
    Bank(vector<long long>& balance) {
       b = balance; 
    }
    bool valid(int a){
        return a >= 1 && a <= b.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(!valid(account1) || !valid(account2)){
            return false;
        }
       bool res = withdraw(account1, money);
       if(res) deposit(account2, money);
       return res;
    }
    
    bool deposit(int account, long long money) {
        if(!valid(account)){
            return false;
        }
        if(account < 1 || account > b.size())return false;
        b[account-1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(!valid(account)){
            return false;
        }
       if(b[account-1] < money || account < 1 || account > b.size()) return false;
       b[account-1]-=money; 
       return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */