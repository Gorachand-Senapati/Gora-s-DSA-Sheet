//my approach
class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<string>prefix;
        
        string t = "";
        for(int i=0;i<n-1;i++){
            t+= s[i];
            prefix.push_back(t);
        }
        string p = "";
        for(int i=1;i<n;i++){
            string suf = s.substr(i);
            if(find(prefix.begin(), prefix.end(),suf) != prefix.end()){
                string ans = suf;
                return ans;
            }
        }
        return "";
    }
};
//striver bfa
class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
       
       for(int len = n-1; len > 0;len--){
          if(s.substr(0,len) == s.substr(n-len,len)){//check last and 1st
            return s.substr(0,len) ;
          }
       }
        return "";
    }
}; //both time memory limit exceed

//KMP algorithm USING LPS array
class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int>lps(n,0);
        int len =0, i =1;
        while(i < n){
            if(s[i] == s[len]){
                len++;
                lps[i]= len;//last n-1 = max len prefix stay
                i++;
            }else{
                if(len != 0){
                    len = lps[len - 1] ;//We already matched something before, try a smaller valid prefix instead of restarting
                }else{//if len =0
                    lps[i] =0;
                    i++;
                }
            }
        }
        return s.substr(0,lps[n-1]);
    }
};