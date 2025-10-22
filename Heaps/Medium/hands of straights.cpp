class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;//if total card can not divide evenly false
        map<int, int>freq;
        for(int card: hand){//store the freq of every number
            freq[card]++;
        }
        auto it = freq.begin();
        while(it != freq.end()){
            if(it->second == 0){
                it++;
                continue;//skip
            }
            int start = it->first;
            int count = it->second;
            for(int i=0;i<groupSize;i++){
                //if the current required card is missing return false;
                if(freq[start+i] < count) return false;
                 freq[start+i] -= count;//count decrease
            }
            it++;
        }
        return true;
    }
};