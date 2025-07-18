class Solution {
public:
    int reverse(int n) {
        int revNum =0;

        while(n!=0){
            int dig= n%10;
            //for prevent out of bound means if reverse number maximum er chey boro ba minimum er theke khub choto takhn 10 dea gun korar age check kore nite hobe
            if(revNum >INT_MAX/10 || revNum < INT_MIN/10){
                return 0;
            }
            revNum= (revNum *10)+dig;
            n= n/10;

        }
        return revNum;
    }
};