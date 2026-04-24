class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string s=a; int cnt =1;
        while(s.size() < b.size()){
            cnt++;
            s+=a;
        }
        if(s.contains(b))return cnt;
        cnt++;
        s+=a;
        if(s.contains(b))return cnt;
        return -1;
    }
};