/*
    Given the weights and profits of N items, 
    in the form of {profit, weight} put these items in a knapsack of capacity W to get the maximum total profit in the knapsack. 
    In Fractional Knapsack, we can break items for maximizing the total value of the knapsack

    Input: arr[] = {{60, 10}, {100, 20}, {120, 30}}, W = 50
    Output: 240 
    Explanation: By taking items of weight 10 and 20 kg and 2/3 fraction of 30 kg. 
    Hence total price will be 60+100+(2/3)(120) = 240

    Input:  arr[] = {{500, 30}}, W = 10
    Output: 166.667
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <bits/stdc++.h>
#include <set>
using namespace std;

#define ll long long
#define loop(I, S) for (int I = 0; I < S; I++)
#define loop_cond(I,S,U) for (I = 0; I < S; #U)
#define getVector(n, vt) for (auto n : vt)
#define shift_left(n) (1 << n)
#define shift_right(n) (1 >> n)

static bool compare(const vector<int>& a, const vector<int>& b) {
    double r_1 = (double)a[0] / (double)a[1];
    double r_2 = (double)b[0] / (double)b[1];
    return r_1 > r_2;
}

double fractionalKnapsack(vector<vector<int>>& knaps, int weight) {
    double profits = 0;
    // Sorting for sure that the next profits is the optimal
    sort(knaps.begin(), knaps.end(), compare);

    // Handle greedy
    loop(i, knaps.size()) {
        if (weight <= 0) {
            break;
        }
        if (knaps[i][1] <= weight) {
            profits += knaps[i][0];
            weight -= knaps[i][1];
        }
        else {
            double _remain = (double)weight/knaps[i][1];
            profits += ( _remain * knaps[i][0] );
            weight = 0;
        }
    }
    return profits;
}

// building in std=c++11
void start_without_input() {
    vector<vector<int>> inp = {
        {60, 10}, {100, 20}, {120, 30}
    };
    cout << fractionalKnapsack(inp, 50) << endl;
    inp = {
        {500,30}
    };
    cout << fractionalKnapsack(inp, 10) << endl;
}

int main() {
    start_without_input();
    return 0;
}
