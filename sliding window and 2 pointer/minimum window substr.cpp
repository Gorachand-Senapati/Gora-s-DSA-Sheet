class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        int stIdx = -1;
        long long minLen = 1e9;

        for (int i = 0; i < n; i++) {
            int freq[256] = {0};
            for (char c : t) freq[c]++;   // ✅ initialize with target

            int cnt = 0;
            for (int j = i; j < n; j++) { // ✅ scan from i to end
                if (freq[s[j]] > 0) {
                    cnt++;
                }
                freq[s[j]]--; // ✅ always decrement (handles extra chars too)

                if (cnt == m) { // ✅ found all chars
                    if ((j - i + 1) < minLen) {
                        minLen = j - i + 1;
                        stIdx = i; // ✅ update only when better
                    }
                    break;
                }
            }
        }

        if (stIdx == -1) return "";
        return s.substr(stIdx, minLen);
    }
};


class Solution {
public:
    string minWindow(string s, string t) {
        int freq[256]={0};
        int r=0, l=0; long long minLen=1e9;
        int n=s.size(), m= t.size();
        int cnt=0; int sIdx=-1;
        for(int i=0;i<m;i++){//O(m)
            freq[t[i]]++;
        }
        while(r<n){ // O(n)
            if(freq[s[r]] > 0){
                cnt+=1;
            }
            freq[s[r]]--;//deccrease
            while(cnt==m){//O(n)
                if((r-l+1)<minLen){
                    minLen= r-l+1;
                   sIdx=l;
                }
                freq[s[l]]++;//increase freq
                if(freq[s[l]] > 0){
                    cnt-=1;
                }
                l++;
            }
            r+=1;
        }
        return sIdx == -1 ? "":s.substr(sIdx, minLen);
    }
};