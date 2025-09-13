class Solution {
public:
 bool isVowel(char c){
   c= tolower(c);
   return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
 }
    string sortVowels(string s) {
        string temp;
        for(char ch:s){
            if(isVowel(ch)){
                temp.push_back(ch);
            }
        }
        sort(temp.begin(), temp.end());
        int j=0;
        for(int i=0;i<s.size();i++){
            if(isVowel(s[i])){
                s[i]=temp[j];
                j++;
            }
        }
 return s;
    }
}; // Time Complexity: O(n log n) due to sorting the vowels

//Optimise with counting sort
class Solution {
public:
  bool isVowel(char c){
   c= tolower(c);
   return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
 }
    string sortVowels(string s) {
        unordered_map<char, int>mp;
        for(auto ch:s){
            if(isVowel(ch)){
                mp[ch]++;
            }
        }
        string temp="AEIOUaeiou";//all vowel with sorted
        int j=0;
        for(int i=0;i<s.size();i++){
            if(isVowel(s[i])){
                while(mp[temp[j]]==0){
                    j++;//if map count 0 then check next
                }
                s[i]=temp[j];
                mp[temp[j]]--;
            }
        }
        return s;
    }
};