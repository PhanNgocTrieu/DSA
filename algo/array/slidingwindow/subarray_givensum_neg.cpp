/*
    Given an unsorted array of integers, 
    find a subarray that adds to a given number. If there is more than one subarray with the sum of the given number, print any of them.

    Input: arr[] = {1, 4, 20, 3, 10, 5}, sum = 33
    Output: Sum found between indexes 2 and 4
    Explanation: Sum of elements between indices 2 and 4 is 20 + 3 + 10 = 33

    Input: arr[] = {10, 2, -2, -20, 10}, sum = -10
    Output: Sum found between indexes 0 to 3
    Explanation: Sum of elements between indices 0 and 3 is 10 + 2 – 2 – 20 = -10
    
    Input: arr[] = {-10, 0, 2, -2, -20, 10}, sum = 20
    Output: No subarray with given sum exists
    Explanation: There is no subarray with the given sum
*/
#include <bits/stdc++.h>
using namespace std;

void find_subarray_with_given_sum_normal(const vector<int>& nums, int sum) {
    for (int i = 0; i < nums.size(); i++) {
        int cur_sum = nums[i];
        for (int j = i + 1; j < nums.size(); j++) {
            cur_sum += nums[j];
#if ARRAY_IS_POSITIVE_ONLY
            if (cur_sum > sum) {
                // Handle
                break;
            }
#endif
            if (cur_sum == sum) {
                cout << "Sum found between indexes " << i << " and " << j << endl;
                return;
            }
        }
    }
    cout << "No subarray with given sum exists" << endl;
}

void find_subarray_with_given_sum_hashmap(const vector<int>& nums, int sum) {
    unordered_map<int, int> map;
    int cur_sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        cur_sum += nums[i];

        if (cur_sum == sum) {
            cout << "Sum found between indexes " << 0 << " and " << i << endl;
            return;
        }

        if (map.find(cur_sum - sum) != map.end()) {
            cout << "Sum found between indexes " << map[cur_sum - sum] + 1 << " and " << i << endl;
            return;
        }
        map[cur_sum] = i;
    }
    cout << "No subarray with given sum exists" << endl;
}

int main() {
    find_subarray_with_given_sum_normal({1, 4, 20, 3, 10, 5}, 33);
    find_subarray_with_given_sum_normal({10, 2, -2, -20, 10}, -10);
    find_subarray_with_given_sum_normal({-10, 0, 2, -2, -20, 10}, 20);
    return 0;
}
