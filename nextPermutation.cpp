#include <iostream>
#include <vector>


class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        bool flag = false;
        for (int i = nums.size() - 1; i >= 0; --i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[j] > nums[i]) {
                    std::swap(nums[i], nums[j]);
                    flag = true;
                    break;
                }
            }
            if (flag == true) {
                break;
            } else {
                int k = i;
                while (k + 1 != nums.size() and nums[k] > nums[k + 1]) {
                    std::swap(nums[k], nums[k + 1]);
                    k++;
                }
            }
        }
    }
};


int main() {
    std::vector<int> nums = {3, 2 , 1};
    Solution().nextPermutation(nums);
    for (auto i : nums) {
        std::cout << i << " ";
    }
    return 0;
}
