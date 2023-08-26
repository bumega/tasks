#include <iostream>
#include <map>
#include <vector>

int main() {
    int n;
    std::string s1, s2;
    std::cin >> n;
    std::map<char, std::vector<int>> sch1;
    std::map<char, std::vector<int>> sch2;
    std::map<char, std::vector<int>>::iterator iter;
    std::map<char, std::vector<int>>::iterator s_iter;
    bool flag;
    for (int i = 0; i < n; ++i) {
        sch1.clear();
        sch2.clear();
        flag = true;
        std::cin >> s1;
        std::cin >> s2;
        for (int ind = 0; ind < s1.size(); ++ind) {
            iter = sch1.find(s1[ind]);
            if (iter != sch1.end()) {
                (iter->second).push_back(ind);
            } else {
                sch1.insert({s1[ind], {ind}});
            }
        }
        for (int ind = 0; ind < s2.size(); ++ind) {
            iter = sch2.find(s2[ind]);
            if (iter != sch2.end()) {
                (iter->second).push_back(ind);
            } else {
                sch2.insert({s2[ind], {ind}});
            }
        }

        for (int ind = 0; ind < s1.size(); ++ind) {
            iter = sch1.find(s1[ind]);
            s_iter = sch2.find(s2[ind]);
            if (iter->second != s_iter->second) {
                flag = false;
                break;
            }
        }
        if (flag) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }

    }
    return 0;
}
