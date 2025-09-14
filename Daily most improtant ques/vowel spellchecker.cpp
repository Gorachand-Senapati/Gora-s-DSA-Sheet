class Solution {
public:
unordered_set<string>exactSet;//for exact match
unordered_map<string, string>caseMap;//for case insensitive match
unordered_map<string, string>vowelMap;//for vowel error match

 string toLower(string &s){
    string result =s;
    for(char & ch: result){//ch convert automatic result convert
        ch=tolower(ch);
    }
    return result;
 }
 string replaceVowel(string &s){
    string result =s;
    for(char& ch : result){
        if(ch=='a' || ch=='e'|| ch=='i' || ch =='o' || ch=='u'){
            ch='*';
        }
    }
 return result;
 }
 
 string checkForMatch(string &query){
    if(exactSet.count(query)){
        return query;
    }
    //case error check uper or lower case
    string lowerCase= toLower(query);
    if(caseMap.count(lowerCase)){//if lowercase map find
        return caseMap[lowerCase];
    }
    //vowel check
    string vowelCase= replaceVowel(lowerCase);
    if(vowelMap.count(vowelCase)){//if find in vowel map
        return vowelMap[vowelCase];
    }
    //if nothing match 
    return "";
 }
 

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        exactSet.clear();
        caseMap.clear();
        vowelMap.clear();
    for(string word : wordlist){//1st all wordlist add to set and map
        exactSet.insert(word);

        string lowerCase= toLower(word);
        if(caseMap.find(lowerCase)== caseMap.end()){//if not find add to map
            caseMap[lowerCase]=word;
        }

        string vowelCase = replaceVowel(lowerCase);
        if(vowelMap.find(vowelCase)== vowelMap.end()){//if not find then add to map
            vowelMap[vowelCase]=word;
        }
    }
    vector<string>result;
    for(string &query : queries){//for every query check present or not if present add to result
        result.push_back(checkForMatch(query));
    }
    return result;
    }
};