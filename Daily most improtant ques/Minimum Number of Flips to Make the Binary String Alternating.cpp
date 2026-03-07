class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string t = s + s;//make a new string where if do type 1 ops then all string present
        //make the alternating string s1 = 0101.. s2= 1010..
        string s1,s2;
        for(int i =0;i<2*n;i++){//make s1,s2 of 2*s.size()
            if(i%2 ==0){
                s1+= '0';
                s2+='1';
            }else{
                s1+='1';
                s2+= '0';
            }
        }
        int ans = INT_MAX;
        int f1 =0, f2 =0;//filip1,filip2 
        int i= 0, j=0;// for siliding window need this

        while(j < 2*n){ //for siliding window j running 1st
           if(t[j] != s1[j]) f1++;
           if(t[j] != s2[j]) f2++;

           if(j-i +1 > n){//shrink the window
            if(t[i]!= s1[i]) f1--;//not same means filip1 previously
            if(t[i]!= s2[i]) f2--;//not same means filip1 previously
            i++;
           }
           
           if(j-i+1 == n){
            ans = min({ans,f1,f2});
           }
           j++;
           
        }
        return ans;
    }
}; // TC: O(n) SC: O(n*2) because we are making 2 string of size 2*n and one string of size 2*n for t.

//if we not add the string t = s+s then we have to do mod operation for every index to get the correct index of s1 and s2 which will increase the time complexity to O(n^2) because for every index we are doing mod operation which is O(n) and we are doing it for n indices.
class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string t  = s;

        string s1,s2;
        for(int i =0;i<2*n;i++){//make s1,s2 of 2*s.size()
            if(i%2 ==0){
                s1+= '0';
                s2+='1';
            }else{
                s1+='1';
                s2+= '0';
            }
        }
        int ans = INT_MAX;
        int f1 =0, f2 =0;//filip1,filip2 
        int i= 0, j=0;// for siliding window need this

        while(j < 2*n){ //for siliding window j running 1st
           if(t[j %n] != s1[j]) f1++;
           if(t[j%n] != s2[j]) f2++;

           if(j-i +1 > n){//shrink the window
            if(t[i%n]!= s1[i]) f1--;//not same means filip1 previously
            if(t[i%n]!= s2[i]) f2--;//not same means filip1 previously
            i++;
           }
           
           if(j-i+1 == n){
            ans = min({ans,f1,f2});
           }
           j++;
           
        }
        return ans;
    }
};// TC: O(n) SC: O(n*2) because we are making 2 string of size 2*n and one string of size n for t.

//best approach O(n) time and O(1) space
class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string t  = s;

        int ans = INT_MAX;
        int f1 =0, f2 =0;//filip1,filip2 
        int i= 0, j=0;// for siliding window need this

        while(j < 2*n){ //for siliding window j running 1st
           char exps1 = (j % 2) ? '1' : '0';//if odd then 1 else 0
           char exps2 = (j % 2) ? '0' : '1';//if odd then 0 else 1
           if(t[j %n] != exps1) f1++;
           if(t[j%n] != exps2) f2++;

           if(j-i +1 > n){//shrink the window
              exps1 = (i % 2) ? '1' : '0';//if odd then 1 else 0
              exps2 = (i % 2) ? '0' : '1';//if odd then 0 else 1
            if(t[i%n]!= exps1) f1--;//not same means filip1 previously
            if(t[i%n]!= exps2) f2--;//not same means filip1 previously
            i++;
           }
           
           if(j-i+1 == n){
            ans = min({ans,f1,f2});
           }
           j++;
           
        }
        return ans;
    }
};