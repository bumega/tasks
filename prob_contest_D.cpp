#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    std::vector<std::pair<size_t, size_t>> beg_c = {{0, 0}};
    std::vector<std::pair<size_t, size_t>> end_t = {{0, 0}};
    std::vector<std::pair<size_t, size_t>>::iterator st;
    std::vector<std::pair<size_t, size_t>>::iterator fn;
    size_t n;
    std::cin >> n;
    size_t b, e, c;
    for (size_t i = 0; i < n; ++i) {
        std::cin >> b >> e >> c;
        beg_c.emplace_back(b, c);
        end_t.emplace_back(e, (e - b));
    }
    std::sort(beg_c.begin(), beg_c.end());
    std::sort(end_t.begin(), end_t.end());
    for (size_t i = 2; i < beg_c.size(); ++i) {
        beg_c[i].second += beg_c[i - 1].second;
        end_t[i].second += end_t[i - 1].second;
    }
    size_t q;
    std::cin >> q;
    std::string zap;
    size_t ans;
    for (size_t i = 0; i < q; ++i) {
        std::cin >> b >> e >> zap;
        ans = 0;
        if (zap == "1"){
            st = std::lower_bound(beg_c.begin() + 1, beg_c.end(), b, [](std::pair<int, int> p1, int p2) {return p1.first < p2;});
            fn = std::upper_bound(beg_c.begin() + 1, beg_c.end(), e, [](int p1, std::pair<int, int> p2) {return p1 < p2.first;});
        } else {
            st = std::lower_bound(end_t.begin() + 1, end_t.end(), b, [](std::pair<int, int> p1, int p2) {return p1.first < p2;});
            fn = std::upper_bound(end_t.begin() + 1, end_t.end(), e, [](int p1, std::pair<int, int> p2) {return p1 < p2.first;});
        }
        ans = (fn - 1)->second - (st - 1)->second;
        std::cout << ans << " ";
    }

    return 0;
}
