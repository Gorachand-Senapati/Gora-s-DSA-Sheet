class Solution {
private: 
   bool isPossible (string & s1, string & s2){
        if(s1.size() != s2.size()+ 1) return false;
        int i =0, j=0;
        while(i < s1.size()){//untill both string exhausted
            if(j <s2.size() && s1[i] == s2[j]){
                i++;j++;
            }else {
                i++;
            }
        }
        if(i == s1.size() && j == s2.size()) return true;
        return false;

    }
    bool static compare(string & s1, string & s2){
        return s1.size() <s2.size();
    }
public:
     int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), compare);//This function is a custom comparator used for sorting strings based on their length.
        vector<int>dp(n,1);
        int maxi =0;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(isPossible(words[i], words[prev]) && dp[i] < 1+dp[prev]){
                    dp[i] = 1+ dp[prev];
                    maxi = max(maxi, dp[prev] +1);
                }
            }
            if(maxi < dp[i]){
                maxi = dp[i];
            }
        }
        return maxi;

    }
};

//find the all predecessor and find it in map and add 1 to it and find the maximum of all the predecessor and return it.
class Solution {
public:

    static bool compare(const string &a, const string &b){
        return a.size() < b.size();
    }

    int longestStringChain(vector<string>& words) {

        sort(words.begin(), words.end(), compare);

        unordered_map<string,int> dp;
        int maxi = 1;

        for(string word : words){

            int best = 1;

            for(int i = 0; i < word.size(); i++){

                string prev = word.substr(0,i) + word.substr(i+1);

                if(dp.count(prev)){
                    best = max(best, dp[prev] + 1);
                }
            }

            dp[word] = best;
            maxi = max(maxi, best);
        }

        return maxi;
    }
};
