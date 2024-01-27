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

Time Complexity:
Calculating the sums of arrays A and B takes O(n) time, where n is the length of the arrays.
Constructing the unordered_set from array B also takes O(n) time in the worst case.
The loop over array A has O(n) iterations.
The dominant factor is the loop over array A, so the overall time complexity is O(n).

Space Complexity:
The space complexity is primarily determined by the unordered_set set_B, which stores the elements of array B. The space complexity is O(n) since it stores up to n elements.
Additionally, there are some constant space requirements for integer variables.
