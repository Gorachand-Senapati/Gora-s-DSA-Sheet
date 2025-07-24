class Solution {
public:
bool isPalindrome(string s){
    string s2 = s;
    reverse(s2.begin(), s2.end());
    return s == s2;//if same then true;else false;
}

void getAllParts(string s, vector<string>&partition,vector<vector<string>>&ans){
    //base case when string size came 0
    if(s.length() == 0){
        ans.push_back({partition});
    }

    for(int i=0;i<s.length();i++){
        string part = s.substr(0,i+1);//give small part for eachfrom 0 substring is the c++ inbuilt function
        if(isPalindrome(part)){
            partition.push_back(part);
            //next part so i+1
        getAllParts(s.substr(i+1), partition, ans);//go to rest of the string 
        partition.pop_back();//backtrack
        }
        
    }
}
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>partition;
        getAllParts(s,partition, ans);
        return ans;
    }
};