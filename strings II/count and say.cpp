class Solution {
public:
    string countAndSay(int n) {
       if(n==1) return "1";//base case
       string say= countAndSay(n-1);//recursion
       //processing
       string res ="";
      for(int i=0;i<say.length();i++){
        char ch = say[i];
        int count =1;

        while(i<say.length()+1 && say[i]== say[i+1]){
           count++; i++;
        }
        res+= to_string(count) + string(1, ch);//string (1,ch) is a process in c++ for char to string conversion
      }
     return res;
    }
};