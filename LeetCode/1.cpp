#include <vector>
#include <algorithm>
#include <iostream>
#include <functional> // 对于 std::greater

int main() {
    std::vector<int> numbers = {4, 1, 3, 5, 2};
    std::sort(numbers.begin(), numbers.end(), std::greater<int>{});

    for(int num : numbers) {
        std::cout << num << " ";
    }

    return 0;
}

