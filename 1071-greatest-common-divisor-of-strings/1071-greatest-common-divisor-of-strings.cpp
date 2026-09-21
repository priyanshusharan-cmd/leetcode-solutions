#include <string>
using namespace std;

class Solution {
public:

    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    string gcdOfStrings(string str1, string str2) {

        // If they cannot be made from the same repeating string
        if (str1 + str2 != str2 + str1)
            return "";

        // Find GCD of their lengths
        int len = gcd(str1.length(), str2.length());

        // First 'len' characters form the answer
        return str1.substr(0, len);
    }
};