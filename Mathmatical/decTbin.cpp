// class Solution {
//   public:
//     int decToBinary(int n) {
//         int ans = 0;
//         int pow = 1;
//         while (n > 0) {
//             int rem = n % 2;
//             n = n / 2;  // 
//             ans += (pow * rem);
//             pow *= 10;
//         }
//         return ans;
//     }
// };

class Solution {
  public:
    string decToBinary(int n) {
        if (n == 0) return "0";

        string binary = "";
        while (n > 0) {
            binary = to_string(n % 2) + binary;
            n = n / 2;
        }
        return binary;
    }
};

//You're building the binary number as a string, character by character, in the correct order. Since strings can hold digits without needing to calculate their place value, you don’t need to multiply by any power.

