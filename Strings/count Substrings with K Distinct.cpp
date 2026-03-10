//bruteforce O(n² log n) TLE
class Solution {
  public:
    int countSubstr(string& s, int k) {
        // code here
        int n =s.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            set<char>st;
            for(int j=i;j<n;j++){
                st.insert(s[j]);
                if(st.size() == k)cnt++;
            }
        }
        return cnt;
    }
};

//optimised approach using sliding window O(n) TC and O(k) SC
class Solution {
  public:
    int atmost(string &s, int k){
        int n = s.size();
        int l =0, ans =0;
        unordered_map<char, int>freq;
        for(int r=0;r<n;r++){
            freq[s[r]]++;
            while(freq.size() > k){
                freq[s[l]]--;
                if(freq[s[l]] == 0) freq.erase(s[l]);
                l++;
            }
            ans += r-l+1;
        }
        return ans;
    }
    int countSubstr(string& s, int k) {
        //atmost k means less than equal k - less than k =k
        return atmost(s,k) - atmost(s,k-1);
    }
};