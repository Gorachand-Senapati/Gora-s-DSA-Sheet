class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives=0, tens=0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                fives++;//increse my wallet with 5
            } else if(bills[i]==10){
                if(fives){//if five coin avaibale then give change who give 10
                    fives--;//fives decrease
                    tens++;//10s increase in my wallet
                } else{
                    return false;
                }
            } else{//if any one give 20
                if(fives && tens){//check 5 or 10 avaiable if yes give this
                    fives--;
                    tens--;
                } else if(fives>=3){//if fives 3 coin avaibale then give this
                    fives-=3;
                } else{
                    return false;
                }
            }
        }
        return true;
    }
};