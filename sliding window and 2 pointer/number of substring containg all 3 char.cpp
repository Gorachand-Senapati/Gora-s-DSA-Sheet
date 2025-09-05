class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            int hash[3] = {0};
            for (int j = i; j < n; j++) {
                hash[s[j] - 'a'] = 1;
                if (hash[0] + hash[1] + hash[2] == 3) {
                    cnt += (n - j); // every extension of this substring will also be valid
                    break;          // no need to check further
                }
            }
        }
        return cnt;
    }
};

class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt = 0;
        int n = s.size();
        int lastSeen[3] = {-1,-1,-1};
        for (int i = 0; i < n; i++) {
            lastSeen[s[i]-'a']=i;
            if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1){
                cnt= cnt+ 1+ min(lastSeen[0] ,min(lastSeen[1] ,lastSeen[2]));//min only do for two numbers
            }
        }
        return cnt;
    }
};
