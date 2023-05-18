#include <iostream>
#include <vector>
#include <unordered_map>

int findMajorityElement(std::vector<int>& arr) {
    int n = arr.size();
    std::unordered_map<int, int> frequency;

    // Count the frequency of each element
    for (int i = 0; i < n; i++) {
        frequency[arr[i]]++;
    }

    // Find the element with frequency greater than n/2
    for (const auto& pair : frequency) {
        if (pair.second > n / 2) {
            return pair.first;
        }
    }

    // If there is no majority element, return -1 or handle the error accordingly
    return -1;
}

int main() {
    std::vector<int> arr = {1, 2, 2, 3, 2, 4, 2};
    int majorityElement = findMajorityElement(arr);

    if (majorityElement != -1) {
        std::cout << "The majority element is: " << majorityElement << std::endl;
    } else {
        std::cout << "No majority element found!" << std::endl;
    }

    return 0;
}
