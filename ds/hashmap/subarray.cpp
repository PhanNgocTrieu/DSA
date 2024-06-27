
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(I, S) for (int I = 0; I < S; I++)
#define getVector(n, vt) for (auto n : vt) \

bool isSubset(vector<int>& cnst_arr, vector<int>& sub) {
#if native_way
    int match = 0;
    for (auto s : sub) {
        for (auto c : cnst_arr) {
            if (c == s) {
                match++;
                break;
            }
        }
    }
    return match == sub.size() ? true : false;
#endif

#ifdef sortmerge_way
    sort(cnst_arr.begin(), cnst_arr.end());
	sort(sub.begin(), sub.end());
    getVector(e, cnst_arr) {
        cout << e << " ";
    }
    cout << endl;
    getVector(e, sub) {
        cout << e << " ";
    }
    cout << endl;
	int arr_size = cnst_arr.size();
	int sub_size = sub.size();
	int i = 0;
	int j = 0;
	while ( i < arr_size && j < sub_size ) {
        if (cnst_arr[i] > sub[j]) {
            return false;
        }
		if (cnst_arr[i] == sub[j]) {
            i++;
            j++;
        }
        else if (cnst_arr[i] < sub[j]) {
			i++;
		}
	}
    return i >= sub_size ? true : false;
#endif

#ifdef frequency_table
    map<int, int> mapping;
    getVector(e, cnst_arr) {
        mapping[e]++;
    }

    getVector(e, sub) {
        if (mapping[e] > 0) {
            mapping[e]--;
        }
        else {
            return false;
        }
    }
    return true;
#endif
}

int main() {
    vector<int> arr = {10, 5, 2, 23, 19, 3, 19};
    vector<int> sub = {19, 5, 3, 19};
    std::cout << "SWPCT: " << isSubset(arr,sub) << std::endl;
    return 0;
}
