#include <iostream>
#include <vector>

// Function to partition the array around a pivot element
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
  
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
  
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Function to find the kth rank element in the array
int findKthRankElement(std::vector<int>& arr, int low, int high, int k) {
    if (k > 0 && k <= high - low + 1) {
        int pivotIndex = partition(arr, low, high);
        
        // If pivotIndex is the kth rank element
        if (pivotIndex - low == k - 1) {
            return arr[pivotIndex];
        }
        
        // If pivotIndex is greater than the kth rank element, search in the left subarray
        if (pivotIndex - low > k - 1) {
            return findKthRankElement(arr, low, pivotIndex - 1, k);
        }
        
        // Else search in the right subarray
        return findKthRankElement(arr, pivotIndex + 1, high, k - pivotIndex + low - 1);
    }
    
    // If k is out of range, return -1 or handle the error accordingly
    return -1;
}

int main() {
    std::vector<int> arr = {9, 2, 5, 1, 7, 3};
    int k = 3;  // Find the 3rd rank element
    
    int n = arr.size();
    int result = findKthRankElement(arr, 0, n - 1, k);
    
    if (result != -1) {
        std::cout << "The " << k << "th rank element is: " << result << std::endl;
    } else {
        std::cout << "Invalid value of k!" << std::endl;
    }
    
    return 0;
}
