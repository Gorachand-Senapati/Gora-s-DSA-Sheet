class Solution {
public: 
   char solve(vector<char>&values, char op){
    if(op =='!'){
        return values[0] == 't' ? 'f' : 't';//t->f, f->t
    }
    //& operation
    if(op =='&'){
        for(char ch: values){
            if(ch =='f')return 'f';
        }
        return 't';
    }
    // | or operation
    if(op =='|'){
        for(char ch: values){
            if(ch =='t')return 't';
        }
        return 'f';
    }
    return 't';//never come here
   }
    bool parseBoolExpr(string expression) {
        int n = expression.size();
        stack<char>st;
        for(int i=0;i<n;i++){
            if(expression[i]==',')continue;
            //when a close bracket find when push
            if(expression[i] == ')'){
                vector<char>values;
                while(st.top() != '('){
                    values.push_back(st.top());
                    st.pop();
                }
                st.pop();//remove open bracket
                char op = st.top();//!,&,|
                st.push(solve(values,op));
            } else{
            st.push(expression[i]);
            }
        }
        return st.top() == 't' ? true: false;
    }
};