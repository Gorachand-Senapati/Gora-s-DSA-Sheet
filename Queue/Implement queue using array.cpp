/*

The structure of the class is
class MyQueue {
private:
    int arr[100005];
    int front;
    int rear;

public :
    MyQueue(){front=0;rear=0;}
    void push(int);
    int pop();
};
 */

 //Assume a circular queue
// Function to push an element x in a queue.
void MyQueue::push(int x) {
    arr[rear] = x;   // place element at rear
    rear++;          // move rear forward
}

// Function to pop an element from queue and return that element.
int MyQueue::pop() {
    if (front == rear) {   // queue is empty
        return -1;
    }
    int val = arr[front];  // take element
    front++;               // move front forward
    return val;
}