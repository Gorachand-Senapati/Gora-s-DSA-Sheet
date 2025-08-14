//space complixity = O(2*n)
// class MinStack {
// public:
//    stack<pair<int, int>> s;//pair of val and minVal
//     MinStack() {
        
//     }
    
//     void push(int val) {
//         if(s.empty()){
//             s.push({val,val});
//         } else {
//             int minVal = min(val,s.top().second);
//             s.push({val, minVal});
//         }
//     }
    
//     void pop() {
//         s.pop();

//     }
    
//     int top() {
//         return s.top().first;
//     }
    
//     int getMin() {
//         return s.top().second;
//     }
// };

//space complixity = O(n)

class MinStack {
public:
  stack<long long int> s;//bcz here multiply with 2 so overflow occured
  long long int minVal;
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()){
            s.push(val);
            minVal = val;
        } else {
            if(val<minVal){
                s.push((long long)2*val - minVal);
                minVal = val;
            } else{
                s.push(val);
            }
        }
    }
    
    void pop() {
       if(s.top()<minVal){
        minVal = 2*minVal - s.top();
       } 
        s.pop();
       }

    
    int top() {
        if(s.top() <minVal){
            return minVal;
        } else{
            return s.top();
        }
    }
    
    int getMin() {
        return minVal;
    }
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */