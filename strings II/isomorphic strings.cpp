class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        if(n != t.size()) return false;
        unordered_map<char, char>m1;//s->t
        unordered_map<char, char>m2;//t->s

        for(int i=0;i<n;i++){
            char c1 = s[i], c2 = t[i];
            //check s->t mapping
            if(m1.count(c1) && m1[c1] != c2) return false;
            //check t->s mapping
            if(m2.count(c2) && m2[c2] != c1) return false;
            m1[c1]= c2;
            m2[c2]= c1;
        }
        return true;
    }
};