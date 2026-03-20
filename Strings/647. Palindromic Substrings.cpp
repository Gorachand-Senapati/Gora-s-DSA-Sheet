class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();int cnt =0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                string p = s.substr(i,j-i+1);//from idx i to j
                string t =p;
                 reverse(p.begin(),p.end());//inline change
                if(p== t)cnt++;
            }
        }
        return cnt;
    }
};