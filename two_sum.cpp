#include <set>
#include <iostream>
#include <vector>
#include <map>



/*
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::multiset<int> search_set{nums.begin(), nums.end()};
        int sec = 0;
        int f_el, s_el;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (search_set.find(target - nums[i]) != search_set.end()) {
                sec = target - nums[i];
                f_el = i;
                break;
            }
        }
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] == sec) {
                s_el = i;
            }
        }
        if (f_el > s_el) {
            std::swap(f_el, s_el);
        }
        std::vector<int> ans = {f_el, s_el};
        return ans;
    }
};*/


class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::set<int> m;
        int nel;
        std::vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            nel = target - nums[i];
            if (m.find(nel) != m.end()) {
                ans.push_back(i);
                break;
            }
            m.insert(nums[i]);
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == nel) {
                ans.push_back(i);
                break;
            }
        }
        if (ans[0] > ans[1]) {
            std::swap(ans[0], ans[1]);
        }
        return ans;
    }
};

int main() {
    std::vector<int> nums = {3, 3};
    int target = 6;
    auto el = Solution().twoSum(nums, target);
    for (auto i : el ) {
        std::cout << i << " ";
    }
    return 0;
}
