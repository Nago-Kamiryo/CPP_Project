#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <ctime>
#include <iterator>
//李俊尚原创代码，用于生成十个随机数求和并排序
int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    std::vector<int> nums;
    // 生成 10 个 [1,100] 的随机整数并存入 vector
    for (int i = 0; i < 10; ++i)
    {
        nums.push_back(std::rand() % 100 + 1);
    }
    std::cout << "原始随机数: ";
    std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    // 使用 std::accumulate 求和
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    std::cout << "随机数的和为: " << sum << std::endl;
    // 使用 std::sort 排序
    std::sort(nums.begin(), nums.end());
    std::cout << "排序后的随机数: ";
    std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    return 0;
}
