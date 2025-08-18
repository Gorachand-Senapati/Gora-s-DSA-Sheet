class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;

        //1st window analize
        for(int i=0; i<k;i++){
            //Non viable elements remove from dque
            while(dq.size() > 0 && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        //for other window
        for(int i=k;i<nums.size();i++){
            ans.push_back(nums[dq.front()]);//ans store 1st window

            //Remove element which are not part of current window
            while(dq.size() > 0 && dq.front() <= i-k) {
                dq.pop_front();
            }

            //Remove the smaller value from ends
            while(dq.size() > 0 && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);//cover the last window
         return ans;
     }
       
 };