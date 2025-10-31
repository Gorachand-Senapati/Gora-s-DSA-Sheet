class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
       int n = nums.size()-2;//original list size bcz extra 2 number add
       int XOR = 0;
       for(int num:nums){//given array xor
        XOR ^= num;
       }
       for(int num = 0; num<=n-1;num++){
        XOR ^= num;//original array xor value
       }
       //make a seperator
       int trailZeroCount = __builtin_ctz(XOR);//make only one set 
       int mask = 1 << trailZeroCount;
       int G1 = 0;//gr-1
       int G2 =0;//gr-2
       for(int num: nums){
        if((num & mask)== 0){
            G1^=num;
        } else{
            G2^= num;
        }
       }
       for(int num =0;num<= n-1;num++){
        if((num & mask)==0){
            G1^=num;
        } else {
            G2^= num;
        }
       }
       return {G1, G2};
    }
};
//also possible using math
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = (int)nums.size() - 2;
        int sum = 0, squaredSum = 0;
        for (int x : nums) {
            sum += x;
            squaredSum += x * x;
        }
        int sum2 = sum - n * (n - 1) / 2;
        int squaredSum2 = squaredSum - n * (n - 1) * (2 * n - 1) / 6;
        int x1 = (sum2 - sqrt(2 * squaredSum2 - sum2 * sum2)) / 2;
        int x2 = (sum2 + sqrt(2 * squaredSum2 - sum2 * sum2)) / 2;
        return {x1, x2};
    }
};

//BFA
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> res;
        unordered_map<int, int> count;
        for (int x : nums) {
            count[x]++;
            if (count[x] == 2) {
                res.push_back(x);
            }
        }
        return res;
    }
};