#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>

class Solution {
public:
    bool equalFrequency(std::string word) {
         std::map<char, size_t> am;
         for (auto el : word) {
             am[el] += 1;
         }
         std::pair<std::pair<size_t, size_t>,std::pair<size_t, size_t>> num;
         num.first.first = am.begin()->second;
         bool flag = true;
         for (auto el : am) {
             if (el.second == num.first.first) {
                 num.first.second += 1;
             } else if (el.second != num.first.first and flag) {
                 flag = false;
                 num.second.first = el.second;
                 num.second.second += 1;
             } else if (el.second == num.second.first) {
                 num.second.second += 1;
             } else {
                 return false;
             }
         }
         std::cout << num.first.first << " " << num.first.second << " " << " " << num.second.first << " " << num.second.second << "\n";
        if (num.second.first > num.first.first) {
            std::swap(num.second, num.first);
        }
         if (num.first.second == 1 or num.second.second == 1) {
             return true;
         }
         if (num.first.first - num.second.first == 1 and num.first.second == 1) {
             return true;
         }
         return false;
    }
};

int main() {
    Solution().equalFrequency("cccd");
    return 0;
}
