#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Method 1: Using sum formula
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expectedSum = n * (n + 1) / 2;  // Sum of 0 to n
        int actualSum = 0;
        
        for (int num : nums) {
            actualSum += num;
        }
        
        return expectedSum - actualSum;
    }
    
    // Method 2: Using XOR (alternative approach)
    int missingNumberXOR(vector<int>& nums) {
        int n = nums.size();
        int xorResult = n;  // Start with n
        
        for (int i = 0; i < n; i++) {
            xorResult ^= i ^ nums[i];
        }
        
        return xorResult;
    }
};

int main() {
    Solution solution;
    
    // Test case 1: [3,0,1] -> missing 2
    vector<int> nums1 = {3, 0, 1};
    cout << "Test 1: [3,0,1] -> Missing number: " << solution.missingNumber(nums1) << endl;
    
    // Test case 2: [0,1] -> missing 2
    vector<int> nums2 = {0, 1};
    cout << "Test 2: [0,1] -> Missing number: " << solution.missingNumber(nums2) << endl;
    
    // Test case 3: [9,6,4,2,3,5,7,0,1] -> missing 8
    vector<int> nums3 = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    cout << "Test 3: [9,6,4,2,3,5,7,0,1] -> Missing number: " << solution.missingNumber(nums3) << endl;
    
    // Test using XOR method
    cout << "\nUsing XOR method:" << endl;
    cout << "Test 1 (XOR): " << solution.missingNumberXOR(nums1) << endl;
    
    return 0;
}