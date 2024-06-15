/*
    Given an array arr[] of non-negative integers and an integer sum, find a subarray that adds to a given sum.
    
    Note: There may be more than one subarray with sum as the given sum, print first such subarray. 

    Input: arr[] = {1, 4, 20, 3, 10, 5}, sum = 33
        Output: Sum found between indexes 2 and 4
        Explanation: Sum of elements between indices 2 and 4 is 20 + 3 + 10 = 33

*/

#include <bits/stdc++.h> 
#include <vector>
using namespace std;

void find_subarray_with_given_sum_normal(const vector<int>& nums, int sum) {
    int max_sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        max_sum = nums[i];
        for (int j = i + 1; j < nums.size(); j++) {
            max_sum += nums[j];
            if (max_sum > sum) {
                break;
            }
            if (max_sum == sum) {
                std::cout << "Sum found beween indexes " << i << " and " << j << endl;
                return;
            }
        }
    }
    std::cout << "Sum not found" << endl; 
}

void find_subarray_with_given_sum_slidingwindow(const vector<int>& nums, int sum) {
    int start = 0;
    int end = 0;
    int cur_sum = nums[start];
    for (int i = 1; i < nums.size(); i++) {
        end = i;
        cur_sum += nums[end];
        while (cur_sum > sum) {
            cur_sum -= nums[start++];
        }

        if (cur_sum == sum) {
            std::cout << "Sum found beween indexes " << start << " and " << end << endl;
            return;
        }
    }
    std::cout << "Sum not found" << endl; 
}


int main() {
    find_subarray_with_given_sum_normal({1, 4, 20, 3, 10, 5}, 33);
    find_subarray_with_given_sum_normal({1, 4, 0, 0, 3, 10, 5}, 7);
    find_subarray_with_given_sum_slidingwindow({1, 4, 20, 3, 10, 5}, 33);
    find_subarray_with_given_sum_slidingwindow({1, 4, 0, 0, 3, 10, 5}, 7);
    return 0;
}

/*
Output:
Sum found beween indexes 2 and 4
Sum found beween indexes 1 and 4
Sum found beween indexes 2 and 4
Sum found beween indexes 1 and 4
*/
