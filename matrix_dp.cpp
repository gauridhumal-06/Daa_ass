#include <iostream>
#include <vector>

// Function to calculate the minimum number of scalar multiplications
int matrixChainMultiplication(const std::vector<int>& dimensions) {
    int n = dimensions.size() - 1; // Number of matrices
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

    // Solve the matrix chain multiplication problem using dynamic programming
    for (int length = 2; length <= n; length++) {
        for (int i = 0; i < n - length + 1; i++) {
            int j = i + length - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + dimensions[i] * dimensions[k + 1] * dimensions[j + 1];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    return dp[0][n - 1];
}

int main() {
    std::vector<int> dimensions = {10, 30, 5, 60};

    int minimumScalarMultiplications = matrixChainMultiplication(dimensions);

    std::cout << "The minimum number of scalar multiplications is: " << minimumScalarMultiplications << std::endl;

    return 0;
}
