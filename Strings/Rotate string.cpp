class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size())return false;
        string doubleds= s + s;//concatination
      return doubleds.find(goal) < doubleds.size();
    }
};