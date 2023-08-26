#include <iostream>
#include <vector>


///функция которая возвращает количество предшествующих элементов
int bin_search(int num, std::vector<int>& arr) {
    int beg = 0;
    int end = arr.size() - 1;
    if (arr[beg] >= num) {
        return 0;
    } else if (arr[end] <= num) {
        return end;
    }
    int mid;
    while (beg < end - 1) {
        mid = (beg + end) / 2;
        if (arr[mid] > num) {
            end = mid;
        } else {
            beg = mid;
        }
    }
    return end;
}


class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        if ((nums1.size() + nums2.size()) % 2 == 1) {
            int target = ((nums1.size() + nums2.size())  / 2);
            int mid;
            int beg = 0;
            int end = nums1.size() - 1;
            while (beg < end - 1) {
                mid = (beg + end) / 2;
                int tmp = mid + bin_search(nums1[mid], nums2);
                if (tmp == target) {
                    return nums1[mid];
                } else if (tmp < target) {
                    beg = mid;
                } else {
                    end = mid;
                }
            }
            int bb = bin_search(nums1[beg], nums2);
            int ee = bin_search(nums1[end], nums2);
            if (beg + bb == target) {
                return nums1[beg];
            } else if (end + ee == target) {
                return nums1[end];
            }
            while (bb < ee - 1) {
                mid = (bb + ee) / 2;
                int tmp = mid + bin_search(nums2[mid], nums1);
                if (tmp == target) {
                    return nums2[mid];
                } else if (tmp < target) {
                    bb = mid;
                } else {
                    ee = mid;
                }
            }
            int bb1 = bin_search(nums2[bb], nums1);
            int ee1 = bin_search(nums2[ee], nums1);
            if (bb + bb1 == target) {
                return nums2[bb];
            } else if (ee + ee1 == target) {
                return nums2[ee];
            }
        } else {

        }
    }
};








int main() {
    std::vector<int> vec1 = {1, 3};
    std::vector<int> vec2 = {2};
    std::cout << Solution().findMedianSortedArrays(vec1, vec2);
    return 0;
}
