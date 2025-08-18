class MyStack {
public:
   queue<int>q1;
   queue<int>q2;
    MyStack() {
        
    }
    
    void push(int x) { //O(n)
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
         while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    int pop() {//O(1)
        int ans = q1.front();
        q1.pop();
        return ans;
    }
    
    int top() {//O(1)
        return q1.front();
    }
    
    bool empty() {//O(1)
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
#include <bits/stdc++.h>
using namespace std;

class MyStack {
    queue<int> q;

public:
    // Push element onto stack
    void push(int x) {
        q.push(x);
        int sz = q.size();
        // Rotate: bring new element to front
        for (int i = 0; i < sz - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    // Removes top element
    int pop() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        int x = q.front();
        q.pop();
        return x;
    }

    // Get top element
    int top() {
        if (q.empty()) return -1;
        return q.front();
    }

    // Check empty
    bool empty() {
        return q.empty();
    }
};

int main() {
    MyStack st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << st.top() << "\n"; // 30
    cout << st.pop() << "\n"; // 30
    cout << st.top() << "\n"; // 20
    cout << st.pop() << "\n"; // 20
    cout << st.pop() << "\n"; // 10
    cout << st.pop() << "\n"; // Stack is empty
}
