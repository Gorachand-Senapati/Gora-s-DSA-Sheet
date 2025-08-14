/*The structure of the class is
class SortedStack{
public:
    stack<int> s;
    void sort();
};
*/

/* The below method sorts the stack s
you are required to complete the below method */
void sortInsert(stack<int>&s, int x){
    if(s.empty() || s.top()<x) {
        s.push(x);
        return ;
    }
    int temp = s.top();
    s.pop();
    sortInsert(s,x);
    s.push(temp);
}
void SortedStack ::sort() {
    // Your code here
    if(!s.empty()){
        int x =s.top();
        s.pop();
        sort();
        sortInsert(s,x);
    }
}
