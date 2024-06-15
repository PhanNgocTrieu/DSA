/*
    Given an array of integers of size ‘n’, Our aim is to calculate the maximum sum of ‘k’ consecutive elements in the array.

    Input  : arr[] = {100, 200, 300, 400}, k = 2
    Output : 700

    Input  : arr[] = {1, 4, 2, 10, 23, 3, 1, 0, 20}, k = 4 
    Output : 39
    We get maximum sum by adding subarray {4, 2, 10, 23} of size 4.

    Input  : arr[] = {2, 3}, k = 3
    Output : Invalid
    There is no subarray of size 3 as size of whole array is 2.
*/

#include <bits/stdc++.h> 
#include <vector>
using namespace std;

int using_normal_approach(const vector<int>& nums, int k) {
    int max_sum = -1;
    for (int i = 0; i < nums.size(); i++) {
        int sum = 0;
        for (int j = 0; j < k; j++) {
            sum += nums[i + j];
        }
        max_sum = max(max_sum,sum);
    }
    return max_sum;
}

int using_slide_window_algo(const vector<int>& nums, int k) {
    int max_sum = 0;
    // find the first sum
    for (int i = 0; i < k; i++) {
        max_sum += nums[i];
    }
    int cur_sum = max_sum;
    for (int i = k; i < nums.size(); i++) {
        cur_sum += nums[i] - nums[i - k];
        max_sum = max(max_sum, cur_sum);
    }
    return max_sum;
}


int main() {
    cout << using_normal_approach({100, 200, 300, 400}, 2) << endl;
    cout << using_slide_window_algo({100, 200, 300, 400}, 2) << endl;

    return 0;
}

/*
Output:
    700
    700
*/
