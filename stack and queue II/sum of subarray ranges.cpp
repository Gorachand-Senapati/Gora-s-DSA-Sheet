class Solution {
public:
   int n;
   //create sum vector array  for max or min subarray sum
   vector<int>nextSmaller, nextGreater, prevSmaller, prevGreater;

   //find nextSmaller element
   void findNse(vector<int>& nums){
    stack<int>st;//index store 
    int i= n-1;//backtracking
    while(i>=0){
        while(!st.empty() && nums[st.top()] > nums[i]){   // ✅ strict >
            st.pop();
        }
        nextSmaller[i]= st.empty() ? n : st.top();//if empty write size if not the top
        st.push(i);i--;
    }
   }

   //find nextGreater element
   void findNge(vector<int>& nums){
    stack<int>st;//index store 
    int i= n-1;//backtracking
    while(i>=0){
        while(!st.empty() && nums[st.top()] < nums[i]){   // ✅ strict <
            st.pop();
        }
        nextGreater[i]= st.empty() ? n : st.top();//if empty write size if not the top
        st.push(i);i--;
    }
   }

   // find prevSmaller element
   void findPse(vector<int>& nums){
    stack<int>st;
    int i=0;
    while(i<n){
        while(!st.empty() && nums[st.top()] >= nums[i]){  // ✅ non-strict >=
            st.pop();
        }
        prevSmaller[i]= st.empty() ? -1: st.top();
        st.push(i);i++;
    }
   }

   // find prevgreater element
   void findPge(vector<int>& nums){
    stack<int>st;
    int i=0;
    while(i<n){
        while(!st.empty() && nums[st.top()] <= nums[i]){  // ✅ non-strict <=
            st.pop();
        }
        prevGreater[i]= st.empty() ? -1: st.top();
        st.push(i);i++;
    }
   }

    long long subArrayRanges(vector<int>& nums) {
        n= nums.size();
        //give all array default size and value for prev def = -1 and for next def= n
        nextSmaller=vector<int>(n,n);
        nextGreater=vector<int>(n,n);
        prevSmaller= vector<int>(n,-1);
        prevGreater= vector<int>(n,-1);

        //fill Them
        findNge(nums);
        findNse(nums);
        findPse(nums);
        findPge(nums);

        //main work for largest and smallest find
        long long  maxSum =0, minSum=0;
        for(int i=0;i<n;i++){
            long long leftMax= i-prevGreater[i];
            long long rightMax= nextGreater[i]-i;
            maxSum+= 1LL * nums[i] * leftMax * rightMax;

            long long leftMin= i-prevSmaller[i];
            long long rightMin= nextSmaller[i]-i;
            minSum+= 1LL * nums[i] * leftMin * rightMin;
        }

        return maxSum- minSum;
    }
};

