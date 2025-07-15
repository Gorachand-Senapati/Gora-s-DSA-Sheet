class Solution {
public:
    string removeOccurrences(string s, string part) {
        //all are stl function
        while(s.length()> 0 && s.find(part)<s.length()){
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};