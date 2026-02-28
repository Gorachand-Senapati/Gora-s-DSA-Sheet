class Solution {
public:
    int numSteps(string s) {
        int ans =0, carry =0;
        int n =s.size();
        for(int i=n-1;i>=1;i--){//go till 1 index if have 0 or 1  in 0 idx no need opration 
         // '0' = 48 , '1' = 49 ascii value
         int bit =(s[i] - '0') + carry;
            if(bit% 2 == 1){//odd 
                ans+=2;
                carry =1;//1+1 = 10 so carry 1
            }else{
                ans+=1;
            }
        }
        return ans+carry;
    }
};