#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

void rash(std::vector<std::vector<long long >>& rec, long long  ind, std::set<long long >& path, std::set<long long >& stopppers) {
    if (path.find(ind) == path.end()) {
        path.insert(ind);
        long long  a = 0;
        long long  b = 0;
        for (auto el : rec[ind]) {
            if (stopppers.find(el - 3) != stopppers.end()) {
                rec[ind] = {0, 0};
                stopppers.insert(ind);
                path.erase(ind);
                return;
            }
        }
        for (auto el : rec[ind]) {
            if (el == 1) {
                a--;
            } else if (el == 2) {
                b--;
            } else {
                if (rec[el - 3].size() ==  2 and rec[el - 3][0] <= 0 and rec[el - 3][1] <= 0) {
                    if (rec[el - 3][0] == 0 and rec[el - 3][1] == 0) {
                        rec[ind] = {0, 0};
                        stopppers.insert(ind);
                        path.erase(ind);
                        return;
                    } else {
                        a += rec[el - 3][0];
                        b += rec[el - 3][1];
                    }
                } else {
                    rash(rec, el - 3, path, stopppers);
                    if (rec[el - 3][0] == 0 and rec[el - 3][1] == 0) {
                        rec[ind] = {0, 0};
                        stopppers.insert(ind);
                        path.erase(ind);
                        return;
                    } else {
                        a += rec[el - 3][0];
                        b += rec[el - 3][1];
                    }
                }
            }
        }
        rec[ind] = {a, b};
        path.erase(ind);
    } else {
        rec[ind] = {0, 0};
    }

}


int  main() {
    long long  n;
    long long  k;
    long long  el;
    std::vector<std::vector<long long >> rec;
    std::vector<long long > tmp;
    std::set<long long > path;
    std::set<long long > stoppers;
    std::cin >> n;
    for (long long  iter = 0; iter < n - 2; iter++) {
        std::cin >> k;
        for (long long  ing = 0; ing < k; ing++) {
            std::cin  >> el;
            tmp.push_back(el);
        }
        rec.push_back(tmp);
        tmp.clear();
    }
    for (long long  iter = 0; iter < n - 2; iter++) {
        if (rec[iter].size() != 2 or rec[iter][0] > 0 or rec[iter][1] > 0 ) {
            rash(rec, iter, path, stoppers);
        }
    }
    long long  q;
    std::cin >> q;
    long long  a,b,zap;
    for (long long  kgb = 0; kgb < q; kgb++) {
        std::cin >> a >> b >> zap;
        if (abs(rec[zap - 3][0]) <= a and abs(rec[zap - 3][1]) <= b and (rec[zap - 3][0] != 0 or rec[zap - 3][1] != 0)) {
            std::cout << "1";
        } else {
            std::cout << "0";
        }
    }
    return 0;
}
