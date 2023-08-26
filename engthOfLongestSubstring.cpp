#include <iostream>
#include <map>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        size_t beg, end, max;
        std::map<char, size_t> sl;
        beg = 0;
        end = 0;
        max = 0;
        auto y = sl.end();
        for (size_t i = 0; i < s.size(); ++i) {
            end = i;
            y = sl.find(s[i]);
            if (y != sl.end()) {
                if (y->second + 1 > beg) {
                    beg = y->second + 1;
                }
                y->second = i;
            } else {
                sl.insert({s[i], i});
            }
            if (end - beg + 1 > max) {
                max = end - beg + 1;
            }
        }
        return max;
    }
};




int main() {
   std::string str = "abba";
   std::cout << Solution().lengthOfLongestSubstring(str);
    return 0;
}
