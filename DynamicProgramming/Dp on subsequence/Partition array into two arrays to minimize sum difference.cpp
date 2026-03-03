//recursion 
class Solution {
public:
   bool f(int idx, int cnt,int tar, int k, int totSum, int&mini, vector<int>& nums){
    //base case 1 if cnt == k return mini
     if(cnt == k){
        int s1 = tar;
        int s2 = totSum - s1;
        mini = min(mini, abs(s1-s2));
        return true;
     }
     //out of bound edge case
     if(idx <0) return false;
      bool notTake = f(idx-1, cnt,tar,k,totSum,mini,nums);
      bool take = f(idx-1, cnt+1,tar+ nums[idx],k,totSum,mini,nums);
      return take || notTake;
   }
    int minimumDifference(vector<int>& nums) {
        int n = nums.size(), totSum =0;
        if(n%2 != 0) return -1;
        for(int x:nums) totSum+= x;
        int k = n/2;
        int mini =1e9;
        f(n-1,0,0,k,totSum,mini,nums);//start not pick last el so cnt =0, tar =0 
        return mini;
    }
};

//MEET IN THE MIDDLE APPROACH
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int N = nums.size(), res =INT_MAX,sum =0;
        sum = accumulate(nums.begin(), nums.end(),0);//find totSum
        int n = N/2;//1 array size
        vector<vector<int>>left(n+1), right(n+1);//make 2 array of part1 array
        //search every subset using bitmask
        //storing all possible sum in left and right part
        for(int mask =0;mask <(1<<n);mask++){//001,010,011,....111 for subset
            int sz=0, l=0, r=0;
            for(int i=0;i<n;i++){
                if(mask &(1<<i)){
                    sz++;
                    l+= nums[i];
                    r+= nums[i+n];
                }
            }
            //every possible size left and right find
            left[sz].push_back(l);
            right[sz].push_back(r);
        }
        for(int sz=0;sz<=n;sz++){//sorting right for binary search find left closet 
            sort(right[sz].begin(), right[sz].end());
        }
        for(int sz=0;sz<=n;sz++){
            for(auto& a: left[sz]){
                int b = (sum - 2*a)/2, rsz= n-sz;
                auto &v = right[rsz];
                auto itr = lower_bound(v.begin(), v.end(), b);//binary search over right
                if(itr != v.end()) res= min(res,abs(sum-2*(a+(*itr))));
                if(itr != v.begin()) {
                    auto it = itr;
                    it--;
                    res = min(res, abs(sum- 2*(a+(*it))));
                }
            }
        }
        return res;
    }
};