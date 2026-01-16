class Solution {
public:
  string expandFromCenter(string s, int left, int right){
    if(s.length()<=1) return s;
    while(left>=0 && right <=s.length() && s[left] ==s[right]){
        left--;
        right++;
    }
    return s.substr(left+1, right-left-1);//return max string
  }
    string longestPalindrome(string s) {
        string longest ="";

        for(int i=0;i<s.length();i++){
            //odd lengthe
            string odd = expandFromCenter(s,i,i);//for odd center is 1
            string even = expandFromCenter(s,i,i+1);//for odd center is 1

            if(odd.size()>longest.size()) longest = odd;
            if(even.size()>longest.size()) longest = even;
        }
        return longest;
    }
};