class Bank {
public:
   vector<long long>balance;//0 based index but st from ac1 , ac2 ...
   int n;
    Bank(vector<long long>& balance) {
        n= balance.size();
        this->balance = balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        //if any account is invalid or ac1 not the money  [account 1-1]-> 0 based index
        if(account1 > n || account2 > n || balance[account1 -1] < money){
            return false;
        }
        balance[account1-1] -= money;//decrease from ac 1
        balance[account2-1] += money;//increase in acc 2
        return true;
    }
    
    bool deposit(int account, long long money) {
        if(account > n) return false;
        balance[account -1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
         if(account > n || balance[account-1] < money) return false;
        balance[account -1] -= money;
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