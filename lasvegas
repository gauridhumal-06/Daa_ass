Majority element search using Las Vegas and Monte Carlo algo

The majority element search problem involves finding an element in an array that appears more than n/2 times, where n is the size of the array. Las Vegas and Monte Carlo algorithms are two randomized algorithms commonly used to solve this problem. The Las Vegas algorithm always provides the correct result, while the Monte Carlo algorithm has a small probability of returning an incorrect result. Let's go through the steps of both algorithms with an example.

Consider the array: [3, 3, 4, 2, 4, 4, 2, 4, 4].

Las Vegas Algorithm:
1. Randomly select an element from the array as the potential majority element.
2. Count the number of occurrences of the selected element in the array.
3. If the count is greater than n/2, return the selected element as the majority element.
4. If the count is not greater than n/2, repeat steps 1-3 until a majority element is found.

Monte Carlo Algorithm:
1. Randomly select an element from the array as the potential majority element.
2. Count the number of occurrences of the selected element in the array.
3. If the count is greater than n/2, return the selected element as the majority element.
4. If the count is not greater than n/2, repeat steps 1-3 a fixed number of times (e.g., k) or until a majority element is found.
5. If no majority element is found after k iterations, return an error or an arbitrary value.

Here's the implementation of both algorithms in C++:

cpp
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int majorityElementLasVegas(vector<int>& nums) {
    int majority;
    while (true) {
        int index = rand() % nums.size();
        majority = nums[index];

        int count = 0;
        for (int num : nums) {
            if (num == majority) {
                count++;
            }
        }

        if (count > nums.size() / 2) {
            return majority;
        }
    }
}

int majorityElementMonteCarlo(vector<int>& nums, int k) {
    int majority;
    for (int i = 0; i < k; ++i) {
        int index = rand() % nums.size();
        majority = nums[index];

        int count = 0;
        for (int num : nums) {
            if (num == majority) {
                count++;
            }
        }

        if (count > nums.size() / 2) {
            return majority;
        }
    }
    // No majority element found
    return -1;
}

int main() {
    srand(time(NULL));

    vector<int> nums = {3, 3, 4, 2, 4, 4, 2, 4, 4};

    // Las Vegas Algorithm
    int majorityLasVegas = majorityElementLasVegas(nums);
    cout << "Majority Element (Las Vegas Algorithm): " << majorityLasVegas << endl;

    // Monte Carlo Algorithm
    int k = 10; // Number of iterations
    int majorityMonteCarlo = majorityElementMonteCarlo(nums, k);
    if (majorityMonteCarlo != -1) {
        cout << "Majority Element (Monte Carlo Algorithm): " << majorityMonteCarlo << endl;
    } else {
        cout << "No majority element found (Monte Carlo Algorithm)." << endl;
    }

    return 0;
}


In this code, the `majorityElementLasVegas()` function implements the Las Vegas algorithm, while the

 `majorityElementMonteCarlo()` function implements the Monte Carlo algorithm.

The `main()` function demonstrates the usage of both algorithms. It generates a random seed for the random number generator and initializes the input array. Then, it calls the respective functions to find the majority element and prints the result.

Please note that the Monte Carlo algorithm has a small probability of returning an incorrect result. The value of `k` can be adjusted to control the number of iterations in the Monte Carlo algorithm. A higher value of `k` reduces the probability of an incorrect result but increases the runtime.
