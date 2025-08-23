// User function Template for C++

class Solution {
  public:
  int func(int n){ //O(1)
      if(n % 4 ==1) return 1;
      else if(n % 4 == 2) return n+1;
      else if(n % 4 == 3) return 0;
      else return n;
  }
    int findXOR(int l, int r) { //O(1)
        // complete the function here
        return func(l-1) ^ func(r);
    }
};