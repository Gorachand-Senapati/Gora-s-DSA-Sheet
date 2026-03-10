class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        
        int ans=0;
        for(int i=0;i<n;i++){
             vector<int>freq(26,0);
            for(int j=i;j<n;j++){
                   freq[s[j] -'a']++;//every time check the freq
                  int maxi = INT_MIN;int  mini= INT_MAX;
                
                    for(int k=0;k<26;k++){ //O(n^2 *26)
                       if(freq[k] >0){
                         maxi = max(maxi, freq[k]);//find max
                         mini = min(mini, freq[k]);//find min
                       }
                       
                    }
                     ans+= maxi-mini;
            }
        }
        return ans; 
    }
};