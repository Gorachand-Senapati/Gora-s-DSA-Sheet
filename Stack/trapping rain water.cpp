class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        int res =0; int left=0, right=n-1;
        int leftMax=0, rightMax=0;
        
        while(left<=right){
            if(arr[left]<=arr[right]){
                if(arr[left]>leftMax){
                    leftMax= arr[left];
                } else{
                    res+= leftMax- arr[left];
                }
                left++;
            }else{
                if(arr[right]>rightMax){
                    rightMax= arr[right];
                } else{
                    res+= rightMax- arr[right];
                }
                right--;
            }
        }
        return res;
    }
};

//solved by stack
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> st;
        int water = 0;

        for (int i = 0; i < n; i++) {
            // While current bar is higher than the bar at top of stack
            while (!st.empty() && height[i] > height[st.top()]) {
                int top = st.top();
                st.pop();

                if (st.empty()) break; // no left boundary

                int distance = i - st.top() - 1; // width
                int bounded_height = min(height[i], height[st.top()]) - height[top];
                water += distance * bounded_height;
            }
            st.push(i);
        }
        return water;
    }
};
