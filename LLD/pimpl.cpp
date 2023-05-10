/* PIMPL stands for "Pointer to Implementation" and it's a programming technique that allows you to hide the implementation details of a class from its users. This is achieved by separating the class interface from its implementation using a pointer or a reference to a private data structure. */

/* The idea behind PIMPL is to reduce the dependencies between components of your codebase, making your code more modular and easier to maintain. It allows you to change the implementation of a class without affecting its interface, thus minimizing the risk of introducing bugs and breaking code that depends on that class. */

/* Here's an example of how you can implement the PIMPL idiom in C++: */



#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Helper function to compute the absolute difference between two integers
int abs_diff(int a, int b) {
    return (a > b) ? (a - b) : (b - a);
}

// Function to find the nearest pair that sum to a given target in a vector of integers
vector<int> nearest_pair(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end()); // sort the numbers in ascending order
    int left = 0, right = nums.size() - 1;
    int min_diff = INT_MAX; // initialize the minimum difference to the maximum integer value
    vector<int> result(2);
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) {
            // found an exact match, return the pair
            result[0] = nums[left];
            result[1] = nums[right];
            return result;
        } else {
            // update the minimum difference and move the left or right pointer accordingly
            int diff = abs_diff(sum, target);
            if (diff < min_diff) {
                min_diff = diff;
                result[0] = nums[left];
                result[1] = nums[right];
            }
            if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }
    return result;
}

int main() {
    vector<int> nums {1, 5, 3, 6, 4, 2};
    int target = 7;
    vector<int> pair = nearest_pair(nums, target);
    cout << "Nearest pair to " << target << " is (" << pair[0] << ", " << pair[1] << ")" << endl;
    return 0;
}


/* In this example, MyClass is the public class interface that is exposed to its users. It has a private pointer to an implementation class Impl that holds the private data and functions. */

/* In the source file, MyClass's constructor creates a new instance of Impl and stores a pointer to it in pImpl. The destructor releases the memory allocated by pImpl. Finally, MyClass's public function do_something() delegates the call to pImpl's private function do_something_private(), which contains the implementation details. */

/* By using the PIMPL idiom, the implementation details of MyClass are hidden from its users, which means that changes to the implementation details won't affect the public interface of MyClass. */
