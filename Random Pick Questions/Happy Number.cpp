class Solution {
public:
   int sqSum(int n){
    int sum =0;
    while(n >0){
        int dig = n%10;
        sum+= dig* dig;
        n = n/10;
    }
    return sum;
   }
    bool isHappy(int n) {
       //slow fast approach
       int slow =n, fast =n;
       do{
         slow = sqSum(slow);//move 1 steps
         fast =sqSum(fast);//move 1step
         fast = sqSum(fast);//move total 2 stpes
       }while(slow != fast);//cycle looop check
       if(slow == 1)return true;
       return false;
    }
};