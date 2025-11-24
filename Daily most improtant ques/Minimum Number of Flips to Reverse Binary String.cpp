class Solution {
private:
    string decimalTobinary(int n){
        string s ="";
        if(n==0) return "0";
        while(n>0){
            s+=(n%2) +'0';
            n= n/2;
        }
        reverse(s.begin(), s.end());
        return s;
    }
public:
    int minimumFlips(int n) {
        string s = decimalTobinary(n);
        string r =s;
        reverse(r.begin(), r.end());
        int ops = 0;
        for(int i=0;i<s.length();i++){
            if(s[i] != r[i]){
                ops++;
            }
        }

        return ops;
    }
};