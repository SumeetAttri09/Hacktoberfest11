#include <iostream>
#include <vector>
#include <algorithm>
#include <set> // To store unique quadruplets

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end()); // Sort the array
        std::set<std::vector<int>> uniqueQuadruplets; // Use a set to handle unique quadruplets

        int n = nums.size();
        if (n < 4) {
            return {}; // Not enough elements to form a quadruplet
        }

        for (int i = 0; i < n - 3; ++i) {
            // Skip duplicate elements for the first number
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            for (int j = i + 1; j < n - 2; ++j) {
                // Skip duplicate elements for the second number
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                long long remainingTarget = (long long)target - nums[i] - nums[j]; // Use long long to prevent overflow

                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    long long currentSum = (long long)nums[left] + nums[right];

                    if (currentSum == remainingTarget) {
                        uniqueQuadruplets.insert({nums[i], nums[j], nums[left], nums[right]});

                        // Skip duplicate elements for the third number
                        while (left < right && nums[left] == nums[left + 1]) {
                            left++;
                        }
                        // Skip duplicate elements for the fourth number
                        while (left < right && nums[right] == nums[right - 1]) {
                            right--;
                        }
                        left++;
                        right--;
                    } else if (currentSum < remainingTarget) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return std::vector<std::vector<int>>(uniqueQuadruplets.begin(), uniqueQuadruplets.end());
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    std::vector<std::vector<int>> result = sol.fourSum(nums, target);

    std::cout << "Quadruplets that sum to " << target << ":\n";
    for (const auto& quadruplet : result) {
        std::cout << "[";
        for (size_t i = 0; i < quadruplet.size(); ++i) {
            std::cout << quadruplet[i];
            if (i < quadruplet.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]\n";
    }

    std::vector<int> nums2 = {2, 2, 2, 2, 2};
    int target2 = 8;
    std::vector<std::vector<int>> result2 = sol.fourSum(nums2, target2);

    std::cout << "\nQuadruplets that sum to " << target2 << ":\n";
    for (const auto& quadruplet : result2) {
        std::cout << "[";
        for (size_t i = 0; i < quadruplet.size(); ++i) {
            std::cout << quadruplet[i];
            if (i < quadruplet.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]\n";
    }

    return 0;
}
