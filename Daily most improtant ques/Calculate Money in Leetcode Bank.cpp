class Solution {
public:
    int totalMoney(int n) {
        int monday =1;
        int ans =0;
        while(n > 0){
            for (int day =0; day< min(n,7);day++){
                ans+= monday+ day;
            }
            n= n-7;
            monday++;
        }
        return ans;
    }
}; //O(n) time complexity, O(1) space complexity

// Optimized approach O(1) tc & sc
class Solution {
public:
    int totalMoney(int n) {
        int completeWeaks = n/7;
        int fd = 28;//always 1st weak total 28 
        int ld = 28 +(completeWeaks -1)* 7; //lastday = fd + (completeweaks -1) * differance; 35-28=7
        int sum = completeWeaks * (fd + ld)/2;//math formula nth term sum total day * (f+l)/2
        int stDay= completeWeaks+1;//starting day of reaming days 1,2,3...
        int reamSum = 0;
        for(int day=0; day< n%7; day++){//reaming day sum
            reamSum += stDay+ day;  
        }
        return reamSum + sum;
    }
};

//without use for loop
class Solution {
public:
    int totalMoney(int n) {
        int completeWeaks = n/7;
        int fd = 28;//always 1st weak total 28 
        int ld = 28 +(completeWeaks -1)* 7; //lastday = fd + (completeweaks -1) * differance; 35-28=7
        int sum = completeWeaks * (fd + ld)/2;//math formula nth term sum total day * (f+l)/2
        int remain = n%7;
        int stDay= completeWeaks+1;//reaming st day
        //without use for loop 
        int lDay= stDay + remain -1;//stday+ reaming day- diff;//becuse u see all are 1+ completeweaks 
        int reamSum = remain * (stDay + lDay)/2;
        return reamSum + sum;
    }
};