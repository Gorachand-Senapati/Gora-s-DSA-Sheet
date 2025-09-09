class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int r=0;//childs g
        int l=0;//cookies s
        while(l<s.size() && r<g.size()){
            if(g[r]<= s[l]){
                r+=1;
            }
            l+=1;
        }
        return r;
    }
};