#include <iostream>
#include <vector>
#include <algorithm>

int longestIncreasingSubsequence(const std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> dp(n, 1);

    // Calculate the length of the longest increasing subsequence
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }

    // Find the maximum length in the dp array
    int maxLength = 0;
    for (int i = 0; i < n; i++) {
        maxLength = std::max(maxLength, dp[i]);
    }

    return maxLength;
}

int main() {
    std::vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    int length = longestIncreasingSubsequence(nums);

    std::cout << "The length of the longest increasing subsequence is: " << length << std::endl;

    return 0;
}
