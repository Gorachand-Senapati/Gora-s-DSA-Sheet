//2042. Check if Numbers Are Ascending in a Sentence

class Solution {
public:
    bool areNumbersAscending(string s) {
        int n =s.size();
        vector<int>nums;
        for(int i=0;i<n;i++){
            if(isdigit(s[i])){
                int num=0;
                if(s[i] == ' ')continue;
                while(i < n && isdigit(s[i])){
                    num = num* 10 + (s[i]-'0');
                    
                    i++;
                }
                nums.push_back(num);
            }
        }
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>= nums[i+1]) return false;
            
        }
        return true;
    }
};

//space complexity O(n) and time complexity O(n)
class Solution {
public:
    bool areNumbersAscending(string s) {
        int n =s.size();
        int prev =0;
        for(int i=0;i<n;i++){
            if(isdigit(s[i])){
                int num=0;
                if(s[i] == ' ')continue;
                while(i < n && isdigit(s[i])){
                    num = num* 10 + (s[i]-'0');
                    
                    i++;
                }
                if(prev >= num) return false;

                prev = num;
            }
        }
        
        return true;
    }
};