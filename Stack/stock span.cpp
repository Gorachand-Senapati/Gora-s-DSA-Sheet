// class StockSpanner {
// public:

// vector <int>prices;//store all prices which access by index
// stack<int>st; //store indices of privious higher prices
//     StockSpanner() {
        
//     }
//     //monotonic stack problem
//     int next(int price) {
//         int i= prices.size();//today indes
//         prices.push_back(price);//save today price for future comparrision
//         while(!st.empty() && prices[st.top()]<= price){
//             st.pop();//pop when see today value is greater than the previous high value by pop find privious high
//         };
//         int span;
//         if(st.size()==0){
//             span= i+1;//no greater price before so span = i+1
//         } else{
//             span= i-st.top();
//         }
//         st.push(i);//store in stack today index assume it is the prevhigh
//         return span;
//     }
// };

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

 class StockSpanner {
public:
    stack<pair<int,int>> st; // automatically starts empty
    //remove the constructor
    int next(int price) {
        int span = 1;
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};