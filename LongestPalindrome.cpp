#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iterator>
#include <set>
#include <iomanip>
#include <numeric>
#include <map>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        auto reverse = [](std::string str) {std::string res; for (int i = str.size() - 1; i >= 0; i--) { res.push_back(str[i]); } return res;};
        std::string reversed_s = reverse(s);
        size_t m = reversed_s.size();

        LCSuff = new int* [m + 1];
        for (size_t i = 0; i < m + 1; ++i) {
            LCSuff[i] = new int[m + 1];
        }

        std::map<int, std::vector<std::pair<size_t, size_t>>> map_ind = LCSubStr(s, reversed_s, m);

        std::map<int, std::vector<std::pair<size_t, size_t>>>::reverse_iterator it;

        //for (it = map_ind.rbegin(); it != map_ind.rend(); it++) std::cout << it->first << " ";
        //std::cout << std::endl;


        std::string res;

        //std::cout << "X X ";
        //for (auto i : s) std::cout << i << " ";
        //std::cout << std::endl;
        //for (size_t i = 0; i < m + 1; i++) {
        //  if (i == 0) std::cout << "X ";
        //  else std::cout << reversed_s[i - 1] << " ";
        //  for (size_t j = 0; j < m + 1; j++) {
        //    std::cout << LCSuff[i][j] << " ";
        //  }
        //  std::cout << std::endl;
        //}
        //std::cout << std::endl;

        for (it = map_ind.rbegin(); it != map_ind.rend(); it++) {
            for (auto item : it->second) {
                std::pair<size_t, size_t> ind = { item.first, item.second };
                while (LCSuff[ind.first][ind.second] != 0) {
                    res.push_back(reversed_s[ind.second - 1]);
                    ind.first--; ind.second--;
                }
                //std::cout << "curr string = ";
                //for (auto i : res) std::cout << i;
                //std::cout << " Palindromic? - " << isPalindromic(res) << std::endl;
                if (isPalindromic(res)) return res;
                else res.clear();
            }
        }

        return res;
    }

private:
    int** LCSuff;

    std::map<int, std::vector<std::pair<size_t, size_t>>> LCSubStr(std::string X, std::string Y, size_t m) {
        int result = 0;
        //std::pair<size_t, size_t> ind;
        //std::vector<std::pair<size_t,size_t>> vec_ind;
        //std::map<int, std::pair<size_t, size_t>> map_ind;
        std::map<int, std::vector<std::pair<size_t, size_t>>> map_ind;

        for (size_t i = 0; i < m + 1; i++) {
            for (size_t j = 0; j < m + 1; j++) {

                if (i == 0 || j == 0) LCSuff[i][j] = 0;

                else if (X[i - 1] == Y[j - 1]) {
                    LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;

                    if (map_ind.count(LCSuff[i][j])) map_ind[LCSuff[i][j]].push_back({ i,j });
                    else {
                        std::vector<std::pair<size_t, size_t>> temp;
                        temp.push_back({ i,j });
                        map_ind[LCSuff[i][j]] = temp;
                    }


                }

                else LCSuff[i][j] = 0;
            }
        }

        return map_ind;
    }

    bool isPalindromic(std::string s) {
        size_t i = 0, j = s.size()-1;
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }
};

int main() {
    Solution obj;
    std::string str = "abcdbbfcba";
    std::string res = obj.longestPalindrome(str);
    for (auto i : res) std::cout << i;

    return 0;
}
