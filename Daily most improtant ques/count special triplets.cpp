//bfa
class Solution {
public:
    const int MOD = 1e9 +7;
       //bruteforce
    int specialTriplets(vector<int>& nums) {
        int n= nums.size();
        long long result = 0;

        for (int j=1; j<n-1;j++){
            int countLeft= 0, countRight =0;

            for (int i=0;i<j;i++){
                if(nums[i] == 2*nums[j]){
                    countLeft ++;
                }
            }

            for (int k=j+1;k<n;k++){
                if(nums[k] == 2*nums[j]){
                    countRight ++;
                }
            }
        result = (result + 1LL* countLeft *countRight)% MOD;
            
        }
        return (int)result;
        
    }
};

//Two pass
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int M = 1e9+7;
        //create 2 map 
        unordered_map<int,int>leftMp;//value freq
        unordered_map<int,int>rightMp;//value freq
        //1st all store in rightmp
        int ans =0;
        for(int x:nums){
            rightMp[x]++;
        }

        for(int x:nums){
            rightMp[x]--;//1st reduce from right side
            int left = leftMp[x*2];//means 16 ->freq 0 for x =nums[0]
            int right = rightMp[x*2];
            ans = (ans + (1LL * left * right)) % M;
            leftMp[x]++;//left freq increase
        }
        return ans;
    }
};

// One pass solution
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int M = 1e9+7;
        //create 2 map 
        unordered_map<int,int>valid_i;//value freq
        unordered_map<int,int>valid_j;//value freq
        int res =0;
        for(int x:nums){
            //check it valid k or not, means in j map x/2 number's freq present or not
            if(x % 2 ==0 ){
            res = (res+ valid_j[x/2]) % M;
            }
            //now check it valid j or not means if in left side x *2 number's freq present or not
            valid_j[x]= (valid_j[x] + valid_i[x*2]) % M;//in valid_j map give x freq which is valid[i*2] freq
            //last when go second num
            valid_i[x]++;

        }
       
        return res;
    }
};
