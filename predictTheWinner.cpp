#include <iostream>
#include <vector>



/*
class Solution {
public:
    bool PredictTheWinner(std::vector<int>& nums) {
        return func(nums, 0, nums.size() - 1, 0, 0);
    }

    bool func(std::vector<int>& nums, int l, int r, int f, int s) {
        //std::cout << "yepp\n";
        if (l == r) {
            //std::cout << f + nums[l] << " " << s << "\n";
            return f+nums[l] >= s;
        } else if (l + 1 == r) {
            if (nums[l] < nums[r]) {
                std::swap(nums[l], nums[r]);
            }
            //std::cout << f + nums[l] << " " << s + nums[r] << "\n";
            return f + nums[l] > s + nums[r];
        } else {
            return func(nums, l+2, r, f+nums[l], s+nums[l+1]) or func(nums, l, r-2, f+nums[r], s+nums[r-1]) or func(nums, l+1, r-1, f+nums[l], s+nums[r]) or func(nums, l+1, r-1, f+nums[r], s+nums[l]);
        }
    }
};*/

class Solution {
public:
    bool PredictTheWinner(std::vector<int>& nums) {
        return func(nums, 0, nums.size() - 1, 0, 0);
    }

    bool func(std::vector<int>& nums, int l, int r, int sc, int t) {
        std::cout << t << " : " << l << " " << r << " " << sc << "\n";
        ///first player
        if (t % 2 == 0) {
            if (l == r) {
                return sc + nums[l] >= 0;
            } else if (l + 1 == r) {
                return sc + std::max(nums[l], nums[r]) - std::min(nums[l], nums[r]) >= 0;
            } else {
                return func(nums, l, r-1, sc + nums[r], t + 1) or func(nums, l+1, r, sc + nums[l], t + 1);
            }
            ///second player
        } else {
            if (l == r) {
                return sc - nums[l] >= 0;
            } else if (l + 1 == r) {
                return sc - std::max(nums[l], nums[r]) + std::min(nums[l], nums[r]) >= 0;
            } else {
                return func(nums, l+1, r, sc - nums[l], t + 1) and func(nums, l, r-1, sc - nums[r], t + 1);
            }
        }
    }
};




int main() {
    //std::vector<int> nums = {1, 2, 99};
    std::vector<int> nums = {1, 5, 2};
    std::cout << "t" << " : " << "l" << " " << "r" << " " << "sc" << "\n";
    std::cout << Solution().PredictTheWinner(nums);
    return 0;
}
