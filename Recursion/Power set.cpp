class Solution {
  public:
    vector<string> AllPossibleStrings(string s) {
        // Code here
        int n = s.size();
        vector<string>ans;
        for(int i=0;i<(1<<n); i++){//go till 2^n-1 all subsets
         string sub = "";
         for(int j=0;j<n;j++){//go 0 to n-1 all bit check set or not
             if(i & (1<<j)){//left shift & with curent n 
               sub+=s[j];
             }
         }
         ans.push_back(sub);
        }
        //for need lexicography 
        sort(ans.begin(), ans.end());
        return ans;
    }
};