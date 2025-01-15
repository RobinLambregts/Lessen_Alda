#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <numeric> // For accumulating results

// Linear search function
int linearSearch(const std::vector<int>& arr, int target, int& steps) {
    steps = 0;
    for (size_t i = 0; i < arr.size(); ++i) {
        ++steps; // Increment step counter for comparison
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

// Binary search function
int binarySearch(const std::vector<int>& arr, int target, int& steps) {
    steps = 0;
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        ++steps; // Increment step counter for comparison
        int mid = low + (high - low) / 2; // Avoid overflow
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

// Function to generate a sorted array of random numbers
std::vector<int> generateSortedArray(int size) {
    std::vector<int> arr(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 100);

    arr[0] = dist(gen);
    for (int i = 1; i < size; ++i) {
        arr[i] = arr[i - 1] + dist(gen); // Ensure ascending order
    }
    return arr;
}

// Test function
void runTests() {
    std::cout << "SIZE \t ALG1 STEPS \t ALG2 STEPS \t ALG1 TIME \t ALG2 TIME\n";
    for (int size = 1000; size <= 9000; size += 1000) {
        long long totalStepsLinear = 0, totalStepsBinary = 0;
        long long totalTimeLinear = 0, totalTimeBinary = 0;

        for (int i = 0; i < 1000; ++i) {
            auto arr = generateSortedArray(size);
            int target = arr[rand() % size]; // Random target from the array

            int stepsLinear = 0, stepsBinary = 0;

            // Measure linear search
            auto start = std::chrono::high_resolution_clock::now();
            linearSearch(arr, target, stepsLinear);
            auto end = std::chrono::high_resolution_clock::now();
            totalTimeLinear += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
            totalStepsLinear += stepsLinear;

            // Measure binary search
            start = std::chrono::high_resolution_clock::now();
            binarySearch(arr, target, stepsBinary);
            end = std::chrono::high_resolution_clock::now();
            totalTimeBinary += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
            totalStepsBinary += stepsBinary;
        }

        // Average results
        std::cout << size << "\t "
                  << totalStepsLinear / 1000 << "\t\t "
                  << totalStepsBinary / 1000 << "\t\t "
                  << totalTimeLinear / 1000 << " ns\t "
                  << totalTimeBinary / 1000 << " ns\n";
    }
}

int main() {
    runTests();
    return 0;
}
