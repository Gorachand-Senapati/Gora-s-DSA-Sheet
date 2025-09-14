//brute force, TLE O(3^n) SC= O(n)
class Solution {
public:
    bool isValid(string &s, int idx, int cnt) {
        if (cnt < 0) return false; // too many ')'
        if (idx == s.size()) return cnt == 0; // all matched

        if (s[idx] == '(') {
            return isValid(s, idx + 1, cnt + 1);
        } 
        else if (s[idx] == ')') {
            return isValid(s, idx + 1, cnt - 1);
        } 
        else { // '*'
            return isValid(s, idx + 1, cnt + 1)   // treat as '('
                || isValid(s, idx + 1, cnt - 1)   // treat as ')'
                || isValid(s, idx + 1, cnt);      // treat as ''
        }
    }

    bool checkValidString(string s) {
        return isValid(s, 0, 0);
    }
};
//Optimised greedy O(n) SC= O(1)
class Solution {
public:
    bool checkValidString(string s) {
        int min= 0, max=0;//give range
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                min= min+1;
                max=max+1;
            } else if(s[i]==')'){
                min=min-1;
                max= max-1;
            } else{
                min= min-1;//make 0
                max= max+1;//bcz need range 0 to 1 
            }
             if(min<0)min= 0;//no need to do min-1
                if(max<0) return false;// if max -1 then false
        }
       return min==0? true: false;//if min 0 return true else false
    }
};
