class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int i=a.size()-1;
        int j=b.size()-1;
        int carry=0;
        while(i>=0 || j>=0){
            int sum=carry;
            if(i>=0)sum+=a[i--]-'0';//means after add a[i] then go front
            if(j>=0)sum+=b[j--]-'0';////means after add b[j] then go front
            carry=sum>1? 1:0;//if sum>1 then carry 1
            res+=to_string(sum%2);//print 2%2=0,3%2=1
        }
        if(carry)res+=to_string(carry);
        reverse(res.begin(), res.end());
        return res;
    }
};