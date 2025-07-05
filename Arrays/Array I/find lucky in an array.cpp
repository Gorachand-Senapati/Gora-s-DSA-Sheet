class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int>freqmap;

        //count freq of each number 1->2 ;2->2 
       for(int i=0;i<arr.size();i++){
        freqmap[arr[i]]++;
       }
       int lucky = -1;
       for(auto& pair: freqmap){
        int number = pair.first;
        int freq= pair.second;
        if(number == freq){
            lucky = max(lucky, number);
        }
       }
       return lucky;
    
    }
};