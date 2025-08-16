// class Solution {
//   public:
//     int celebrity(vector<vector<int> >& mat) {
//         // code here
//         int n = mat.size();
//         int i=0, j= n-1;
//         while(i<j){
//             if(mat[i][j]==1){
//                 i++;
//             }else{
//                 j--;
//             }
//         }
//         int candidate =i;
//         //verify it candidate
//         for(int k=0;k<n;k++){
//             if(k != candidate && 
//             (mat[k][candidate] ==0 || mat[candidate][k]==1)){
//                 return -1;
//             }
//         }
//         return candidate;
//     }
// };
class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n = mat.size();
        stack<int>s;
        for(int i=0;i<n;i++){
            s.push(i);
        }
        while(s.size()>1){//means more than 1 element 
        int i= s.top();s.pop();
        int j= s.top();s.pop();
        if(mat[i][j]==1){
            s.push(j);
        }else{
            s.push(i);
        }
            
        }
        int candidate =s.top();
        //verify it candidate
        for(int k=0;k<n;k++){
            if(k != candidate && 
            (mat[k][candidate] ==0 || mat[candidate][k]==1)){
                return -1;
            }
        }
        return candidate;
    }
};