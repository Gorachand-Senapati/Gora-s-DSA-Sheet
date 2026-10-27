class Solution {
public:
    string decodeString(string s) {
        int i=0;
        return decode(s,i);
    }
    string decode(const string &s, int &i){
        string res="";
        int num =0;
        while(i<s.size()){
           char c = s[i];
           if(isdigit(c)){
            num= num*10+(c-'0');//build the num
            i++;
           }else if(c == '['){
            i++;
            string inner = decode(s,i);//recurse start 
            for(int k=0;k<num;k++)res+=inner;
            num=0;//reset;
           }else if(c ==']'){
            i++;
            return res;
           }else{
            res+=c;//normal char
            i++;
           }
        }
        return res;
    }
};


//stack pattern 

class Solution {
public:
    string decodeString(string s) {
        stack<int> nums;
        stack<string> strs;

        string curr = "";
        int num = 0;

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            else if (c == '[') {
                nums.push(num);
                strs.push(curr);

                num = 0;
                curr = "";
            }
            else if (c == ']') {
                int repeat = nums.top();
                nums.pop();

                string prev = strs.top();
                strs.pop();

                string temp = "";
                for (int i = 0; i < repeat; i++) {
                    temp += curr;
                }

                curr = prev + temp;
            }
            else {
                curr += c;
            }
        }

        return curr;
    }
};