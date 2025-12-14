class Solution { // O(n* l) l= string length
public:
 bool isValid(string &code){
    if(code.empty()) return false;//empty string
    for(char &ch: code){
        if(!isalnum(ch) && ch != '_'){
            return false;
        }
    }
    return true;//if all maintain
 }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        //new things
        unordered_map<string,int>mp= {
            {"electronics",0}, {"grocery",1},{"pharmacy",2},{"restaurant",3}
        };//store for valid buiseness order
        vector<pair<int,string>>temp;//builine integer, coupne code
        for(int i=0;i<code.size();i++){
            if(isActive[i] && mp.count(businessLine[i])&& isValid(code[i])){
                temp.push_back({mp[businessLine[i]], code[i]});
            }
        }
        sort(temp.begin(), temp.end());
        vector<string>ans;
        for(auto it:temp){
            ans.push_back(it.second);
        }
        return ans;
    }
};