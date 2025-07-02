class Solution {
  public:
    int binaryToDecimal(string &b) {
        int dec = 0;
        int pow = 1;

        // Iterate from right to left (least significant to most significant bit)
        for (int i = b.length() - 1; i >= 0; i--) {
            int bit = b[i] - '0'; // Convert char '0' or '1' to int 0 or 1 reminder
            dec += bit * pow;
            pow = pow* 2;
        }

        return dec;
    }
};


// 🧠 How it  reminder works:
// In C++ (and many other languages), characters like '0', '1', etc., are stored as ASCII values:

// Character	ASCII Code
// '0'	48
// '1'	49
// '2'	50
// ...	...

// So if b[i] = '1' (a character), then:

// b[i] - '0' = 49 - 48 = 1
// If b[i] = '0', then:


// b[i] - '0' = 48 - 48 = 0


    // int binaryToDecimal(int n) {
    //     int ans = 0;
    //     int pow = 1;
    //     while (n > 0) {
    //         int rem = n % 10;
    //         n = n / 10;  //
    //         ans += (pow * rem);
    //         pow *= 2;
    //     }
    //     return ans;
    // }

