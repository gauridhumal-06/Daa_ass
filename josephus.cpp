#include <iostream>

int josephus(int n, int k) {
    if (n == 1) {
        return 0;  // Base case: only one person remains
    } else {
        return (josephus(n - 1, k) + k) % n;
    }
}

int main() {
    int n = 7;  // Number of people
    int k = 3;  // Every 3rd person is eliminated

    int lastPerson = josephus(n, k);
    std::cout << "The position of the last remaining person is: " << lastPerson + 1 << std::endl;

    return 0;
}
