class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int n = nums.size();
        int sum =0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        double avg = sum /n;//if decimal.pont
        int cnt =1;//always greater than 0
        while(true){
            if(cnt >avg && find(nums.begin(), nums.end(), cnt) == nums.end()){
                return cnt;// find(nums.begin(), nums.end(), cnt) == nums.end() use for find cnt in nums
            }
            cnt++;
        }

    }
};