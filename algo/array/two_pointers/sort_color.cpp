/*

    Given an array nums with n objects colored red, white, or blue, 
    sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

    We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
    You must solve this problem without using the library's sort function.

    Example 1:
        Input: nums = [2,0,2,1,1,0]
        Output: [0,0,1,1,2,2]
    
    Example 2:
        Input: nums = [2,0,1]
        Output: [0,1,2]

    [2]
    [0, 2]
    [0, 2, 2]
    [0, 1, 2, 2]
    [0, 1, 1, 2, 2]
    [0, 1, 1, 2, 2, 0]
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int _zer_idx = 0, _one_idx = 0;
        int _sec_idx = nums.size() - 1;
        while (_zer_idx <= _sec_idx) {
            if (nums[_zer_idx] == 0) {
                swap(nums[_zer_idx++],nums[_one_idx++]);
            }
            else if (nums[_zer_idx] == 1) {
                _zer_idx++;
            }
            else if (nums[_zer_idx] == 2){
                swap(nums[_zer_idx],nums[_sec_idx]);
                _sec_idx--;
            }
        }
    }
};

int main() {

}
