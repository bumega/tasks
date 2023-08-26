#include <iostream>
#include <vector>

class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        std::vector<int> pref_sum;
        int sum = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            pref_sum.push_back(sum);
            sum += nums[i];
        }
        pref_sum.push_back(sum);
        size_t b = 0;
        size_t e =  1;
        int ans = pref_sum.size();
        for (auto i : pref_sum) {
            std::cout << i << " ";
        }
        std::cout << "\n";
       while (true) {
           if (pref_sum[e] - pref_sum[b] >= target) {
               if (e - b < ans) {
                   std::cout << e << " " << b << "\n";
                   ans = e - b;
               }
               b++;
           } else {
               if (e == pref_sum.size() - 1) {
                   break;
               }
               e++;
           }
       }
       if (ans == pref_sum.size()) {
           return 0;
       }
       return ans;
    }
};


int main() {
    std::vector<int> v = {2, 3, 1, 2, 4, 3};
    std::cout << Solution().minSubArrayLen(7, v);
    return 0;
}
