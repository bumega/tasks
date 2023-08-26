#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> pref;
        std::vector<int> post;
        std::vector<int> ans;
        int tmp_b = 1;
        int tmp_e = 1;
        for (size_t i = 0; i < nums.size(); ++i) {
            pref.push_back(tmp_b);
            tmp_b *= nums[i];

            post.insert(post.begin(), tmp_e);
            tmp_e *= nums[nums.size() - i - 1];
        }
        for (size_t i = 0; i < nums.size(); ++i) {
            ans.push_back(pref[i] * post[i]);
        }


        return ans;
    }
};



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
