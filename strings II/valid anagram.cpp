class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int count[26] ={0};//consist lower char
        for(char c :s) count[c-'a']++;//1st convert index are 1
        for(char c :t) count[c-'a']--; //again index convert 0 //if freq same then all 0
        for(int i=0;i<26;i++){
            if(count[i]!= 0) return false;
        }
        return true;
    }
};

//if use unordered_map for capital and small 
bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;

    unordered_map<char, int> mp;

    for (char c : s) mp[c]++;
    for (char c : t) mp[c]--;

    for (auto p : mp) {
        if (p.second != 0) return false;
    }
    return true;
}