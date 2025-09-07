class Solution {
public:
  int binSer(vector<int>& nums, int k,vector<long>& ps, int tarIdx){
    int target= nums[tarIdx];
    int l=0, r= tarIdx;
    int bestRes=tarIdx;
    while(l<=r){
        int mid= l+(r-l)/2;
       int cnt = tarIdx - mid + 1;
long windowSum = 1LL * cnt * target;
long currSum = ps[tarIdx] - (mid > 0 ? ps[mid - 1] : 0);
long ops = windowSum - currSum;

      if(ops>k){//invalid
        l= mid+1;
      } else{
        bestRes= mid;
        r=mid-1;
      }
    }
         return tarIdx-bestRes+1;//freq
  }
    int maxFrequency(vector<int>& nums, int k) {
        int n=  nums.size();
        sort(nums.begin(), nums.end());
        vector<long>ps(n);
        ps[0]= nums[0];
        for(int i=1; i<n;i++){
            ps[i]=ps[i-1]+nums[i];
        }
        int res=0;
        for(int tarIdx=0;tarIdx<n;tarIdx++){
            res= max(res,binSer(nums, k, ps, tarIdx));
        }
        return res;
    }
}; // TC= O(n log n) + O(n log n) , SC= O(n)

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int r=0, l=0, res=0;
        long currSum = 0;
        for(r=0;r<n;r++){
            int target= nums[r];
            int cnt= r-l+1;
            long windowSum= 1ll *cnt*target;
             currSum += nums[r];
            long ops= windowSum- currSum;
           if(ops>k){//not give to while
                currSum-=nums[l];
                l++;
                windowSum=1ll*(r-l+1)*target;
                ops= windowSum-currSum;
            }
            res= max(res, r-l+1);
        }
        return res;
    }
};