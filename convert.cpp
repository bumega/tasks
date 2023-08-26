#include <iostream>


class Solution {
public:
    std::string convert(std::string s, int numRows) {
        int step;
        if (numRows == 1) {
            step = 1;
        } else {
            step = 2 * numRows - 2;
        }
        std::string ans;
        int start = 0;
        int tmp;
        int tstep = step;
        while (tstep > 0) {
            tmp = start;
            if (tstep == step) {
                while (tmp < s.size()) {
                    ans += s[tmp];
                    tmp += tstep;
                }
            } else {
                    while (tmp < s.size()) {
                        ans += s[tmp];
                        tmp += tstep;
                        if (tmp < s.size()) {
                            ans += s[tmp];
                            tmp += step - tstep;
                        }
                    }
            }
            tstep -= 2;
            start++;
        }
        if (step != 1) {
            tmp = start;
            while (tmp < s.size()) {
                ans += s[tmp];
                tmp += step;
            }
        }
        return ans;
    }
};



int main() {
    std::string str = "AB";
    std::cout << Solution().convert(str, 1);
    return 0;
}
