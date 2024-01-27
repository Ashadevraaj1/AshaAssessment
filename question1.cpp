#include <iostream>
#include <unordered_set>
#include <vector>

bool solution(const std::vector<int>& A, const std::vector<int>& B, int m) {
    int sum_A = 0, sum_B = 0;

    for (int num : A) {
        sum_A += num;
    }

    for (int num : B) {
        sum_B += num;
    }

    std::unordered_set<int> set_B(B.begin(), B.end());

    int target_diff = (sum_B - sum_A) / 2;

    for (int num : A) {
        int complement = num + target_diff;
        if (set_B.find(complement) != set_B.end()) {
            return true;
        }
    }

    return false;
}

int main() {
    // Example usage:
    std::vector<int> A = {1, 2, 3};
    std::vector<int> B = {4, 5, 6};
    int m = 6;

    bool result = solution(A, B, m);
    std::cout << std::boolalpha << result << std::endl;

    return 0;
}