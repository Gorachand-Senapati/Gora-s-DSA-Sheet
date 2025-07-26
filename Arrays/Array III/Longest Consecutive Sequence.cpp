// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         if(nums.size()== 0) return 0;
//         sort(nums.begin(), nums.end());
//         int len=1;int lastSmaller = INT_MIN, cnt = 0;
//         for(int i=0;i<nums.size(); i++){
//             if(nums[i]-1 == lastSmaller){
//                 cnt+=1;
//                 lastSmaller= nums[i];
//             } else if(nums[i] != lastSmaller){ //here also prevent duplicate or another value change
//                 cnt=1;
//                 lastSmaller= nums[i];
//             }
//             len= max(len, cnt);
//         }
//         return len;
//     }
// };

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n== 0) return 0;
        int longest =1;
        unordered_set<int>st;//create unordered set
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        for(auto it:st){
            //always stating from which previous value not present in set
            if(st.find(it-1) == st.end()){ //it variable which find this
                int cnt =1;
                int x =it;//here 1st value store now check after value present 
                while(st.find(x+1) != st.end()){//if find x+1
                    x=x+1;
                    cnt =cnt+1;
                }
                  longest = max(longest, cnt);
            }
          
        }
        return longest;
    }
};