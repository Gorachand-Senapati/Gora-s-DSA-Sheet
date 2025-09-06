class Solution { //tc O(n2) sc O(256)
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int n= s.size(), maxLen=0;
        map<char, int>m;
        for(int i=0;i<n;i++){
            m.clear();//clear previous elements
            for(int j=i;j<n;j++){
                m[s[j]]++;
                if(m.size() <= k){
                    maxLen= max(maxLen,j-i+1);
                } else{
                    break;
                }
            }
        }
        return maxLen;
    }
};
//
class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int l=0, r=0,maxLen=0;
        int n= s.size();
         map<char,int>freq;
         
        while(r<n){
            freq[s[r]]++;//freq increase
            if(freq.size() >k){
                //I always go 1 step forward not always from start to last so remove while and give 1 as maxconsequtive 1 -III
             if(freq.size() >k && l<=r){ // here if give while then code run 2n
                freq[s[l]]--;//means shrink
                if(freq[s[l]] == 0){
                    freq.erase(s[l]);
                }
                l++;
              } 
            }
            // if(freq.size()<= k){
             if(freq.size()== k){
                maxLen= max(maxLen, r-l+1);
            }
            r++;
        }
        return (maxLen == 0 ? -1 : maxLen);
    }
};