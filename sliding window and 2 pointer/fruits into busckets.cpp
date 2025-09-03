//BFA tc O(n2) sc O(3)
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n= fruits.size();
       int maxLen=0;
        for(int i=0;i<n;i++){
                set<int>s;
            for(int j=i;j<n;j++){
                s.insert(fruits[j]);
                if(s.size()<=2){
                    maxLen= max(maxLen, j-i+1);
                } else{
                    break;
                }
            }
        }
        return maxLen;
    }
};
// optimal TC= O(n) SC= O(3)
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0, r=0,maxLen=0;
        int n= fruits.size();
         map<int,int>freq;
        while(r<n){
            freq[fruits[r]]++;//freq increase
            if(freq.size() >2){//need only 2 unique fruits
                //I always go 1 step forward not always from start to last so remove while and give 1 as maxconsequtive 1 -III
             if(freq.size() >2 && l<=r){ // here if give while then code run 2n
                freq[fruits[l]]--;//means shrink
                if(freq[fruits[l]] == 0){
                    freq.erase(fruits[l]);
                }
                l++;
              } 
            }
            if(freq.size()<= 2){
                maxLen= max(maxLen, r-l+1);
            }
            r++;
        }
        return maxLen;
    }
};