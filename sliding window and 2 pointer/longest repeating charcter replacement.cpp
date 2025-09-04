class Solution {
public:
    int characterReplacement(string s, int k) {
        int n= s.size();int maxLen=0;
        for(int i=0;i<n;i++){
            int freq[26]={0}; int maxFreq=0;
            for(int j=i;j<n;j++){
                freq[s[j]-'A']++;
             maxFreq= max(maxFreq, freq[s[j]-'A']);
              int changes= (j-i+1)-maxFreq;
              if(changes <=k){
                maxLen= max(maxLen, j-i+1);
              } else {
                break;
              }
            }
        }
        return maxLen;
    }
};

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, maxLen = 0, maxFreq = 0;
        int freq[26] = {0};

        while (r < s.size()) {//O(n)
            freq[s[r] - 'A']++;
            maxFreq = max(maxFreq, freq[s[r] - 'A']); // track max freq seen
            // if changes needed > k, shrink window
            if ((r - l + 1) - maxFreq > k) { //here while using the TC= O(2n) becouse while loop never go always n times but small part go to n so
                freq[s[l] - 'A']--;
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};