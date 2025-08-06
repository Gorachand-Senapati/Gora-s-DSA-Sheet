class Solution {
public:
    int myAtoi(string s) {
       int sign=1;//+
        int i=0;
       long res=0; //use long to handle overflow case
       //ignore white space
       while(i<s.size() && s[i]== ' ') i++;
       if(i== s.size()) return 0;
       //sign check + or -
       if(s[i]=='-'){sign=-1;i++;}
       else if(s[i]=='+'){i++;};
       //skip leading 0 and count dig untill any char find
       while(i<s.size()&& isdigit(s[i])){
        res= res*10+(s[i] -'0');//ascii value 7-0 =7 in ascii 55-48 =7 means char-char
        //handle overflow
        if(res*sign >INT_MAX) return INT_MAX;
        if(res*sign <INT_MIN) return INT_MIN;
        i++;
       }
       return (int)(sign* res);//return int value not long
    }
};