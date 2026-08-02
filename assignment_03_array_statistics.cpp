// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>

using namespace std;

int calculateSum(const vector<int>& arr) {
    int sum = 0;
    for (int num : arr) {
        sum += num;
    }
    return sum;
}

double calculateAverage(const vector<int>& arr) {
    if (arr.empty()) return 0.0;
    return static_cast<double>(calculateSum(arr)) / arr.size();
}

int findMaximum(const vector<int>& arr) {
    int max_val = arr[0];
    for (int num : arr) {
        if (num > max_val) {
            max_val = num;
        }
    }
    return max_val;
}

int findMinimum(const vector<int>& arr) {
    int min_val = arr[0];
    for (int num : arr) {
        if (num < min_val) {
            min_val = num;
        }
    }
    return min_val;
}

int main() {
    int n;
    cout << "How many numbers? ";
    if (!(cin >> n) || n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return 1;
    }

    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> numbers[i];
    }

    cout << "\nResults:" << endl;
    cout << "Sum:     " << calculateSum(numbers) << endl;
    cout << "Average: " << calculateAverage(numbers) << endl;
    cout << "Maximum: " << findMaximum(numbers) << endl;
    cout << "Minimum: " << findMinimum(numbers) << endl;

    return 0;
}
