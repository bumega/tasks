#include <iostream>

class Solution {
public:
    double myPow(double x, int n) {
        if (n < -1) {
            if (n % 2 == 0) {
                auto tmp = myPow(x, n / 2);
                return tmp * tmp;
            } else {
                return (1 / x) * myPow(x, n + 1);
            }
        } else if (n == -1) {
            return 1 / x;
        } else if (n == 0) {
            return 1;
        } else if (n == 1) {
            return x;
        } else {
            if (n % 2 == 0) {
                auto tmp = myPow(x, n / 2);
                return tmp * tmp;
            } else {
                return x * myPow(x, n - 1);
            }
        }
    }
};



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
