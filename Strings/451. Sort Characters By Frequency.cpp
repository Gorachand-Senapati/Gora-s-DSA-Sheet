class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int>freq;
        int n = s.size();
        for(int i=0;i<n;i++){
            freq[s[i]]++;
        }
        vector<pair<char,int>> v(freq.begin() , freq.end());
        sort(v.begin(),v.end(), [](auto &a, auto &b){//custom comparetor  it a and b 
            return a.second > b.second;
        });
        string t ="";
        for(auto &it: v){
            for(int i=0;i<it.second;i++){
                t+= it.first;
                if(t.size() == n) break;
            }
        }
        return t;//TC = O(nlogn) for sorting and O(n) for creating the string  overall O(nlogn) and SC = O(n) 
    }
};