class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // brute force aproch

        int n =nums.size();
        vector<int>list;

        // for(int val:nums) {
        //     if(list.size() == 0 || list[0] != val){
        //     int freq =0;
        //     for(int el:nums) {
        //         if(el==val) {
        //             freq++ ;
        //         }
        //     }
        //     if (freq > (n/3)){
        //     list.push_back(val);
        //     }
        //     }
        //     if(list.size()== 2) break;
        // }
        // return list;

        //better approach
        sort(nums.begin(), nums.end());
        //frequency count 
        int freq = 1;//current 

        for(int i=1;i<n;i++){
            if(nums[i]== nums[i-1]){
                freq++;
            } else{
                if(freq >(n/3)){
                    list.push_back(nums[i-1]);
                }
                freq =1;//reset
            }
        }
        if(freq > (n/3)){
            list.push_back(nums[n-1]);
        }
        return list;



    }
};



/////
class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        // Boyer Moore’s Voting Algorithm
        int n = arr.size();
        int cnt1 =0, cnt2 =0;
        int el1= INT_MIN ,  el2 = INT_MIN;
        
        for(int i=0;i<n;i++){
            //any one statement execute
            if(cnt1 == 0 && el2 != arr[i]){
                cnt1++;
                el1= arr[i];
            } else if(cnt2 == 0 && el1 != arr[i]){
                cnt2++;
                el2= arr[i];
            }
            else if(el1 == arr[i]) cnt1++;
            else if(el2 == arr[i]) cnt2++;
            
            else{
                cnt1--;
                cnt2--;
            }
        }
        
        vector<int>ls;
        cnt1 =0,cnt2=0;
        for(int i= 0;i<n;i++){
            if(arr[i]== el1) cnt1++;
            else if(arr[i]== el2) cnt2++;
        }
        
        if(cnt1 > (n/3)) ls.push_back(el1);
        if(cnt2 > (n/3)) ls.push_back(el2);
        
        sort(ls.begin(), ls.end());
        
        return ls;
        
    }
};