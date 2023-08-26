#include <iostream>
#include <vector>
#include <map>

int trans(const std::string& dd, const std::string& hh, const std::string& mm) {
    return std::stoi(dd) * 1440 + std::stoi(hh) * 60 + std::stoi(mm);
}



int main() {
   int n;
   std::cin >> n;
   std::vector<std::string> log_s;
   std::string t;
   std::map<int, int> ans;
   int time;
   for (int i = 0; i < n; ++i) {
       for (int i = 0; i < 5; ++i) {
           std::cin >> t;
           log_s.push_back(t);
       }
       time = trans(log_s[0], log_s[1], log_s[2]);
       if (log_s[4] == "A") {
           time *= -1;
       }
       if (log_s[4] != "B") {

           if (ans.find(std::stoi(log_s[3])) == ans.end()) {
               ans.insert({std::stoi(log_s[3]), time});
           } else {
               ans[std::stoi(log_s[3])] += time;
           }
       }
       log_s.clear();
   }
   for (auto el : ans) {
       std::cout << el.second << " ";
   }

    return 0;
}
