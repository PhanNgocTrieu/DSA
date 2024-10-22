/*
    A divide-and-conquer algorithm works by recursively breaking the problem
   down into two or more subproblems of the same or related type, until these
   subproblems become simple enough to be solved directly [1]. Then one combines
   the results of subproblems to form the final solution.

    Steps:
    1. Divide. Divide the problem SS into a set of subproblems:
   {S1,S2,...Sn}{S1​,S2​,...Sn​} where n≥2n≥2, i.e. \ there are
   usually more than one subproblem.
    2. Conquer. Solve each subproblem recursively.
    3. Combine. Combine the results of each subproblem.

                            [Problem]
                          /           \
                        /               \
                    [SubProblem]     [Subproblem]
                        |                   |
                    [SubProblem]     [Subproblem]
                        \                  /
                         \               /
                               [Combine]


*/

#include <bits/stdc++.h>
using namespace std;

vector<int> merge_component(const vector<int> &left, const vector<int> &right);

vector<int> merge(const vector<int> arr)
{
  if (arr.size() <= 1)
  {
    return arr;
  }

  int pos = arr.size() / 2;
  vector<int> left = merge({arr.begin(), arr.begin() + pos});
  vector<int> right = merge({arr.begin() + pos, arr.end()});

  return merge_component(left, right);
}

vector<int> merge_component(const vector<int> &left, const vector<int> &right)
{
  vector<int> result(left.size() + right.size());
  int left_cursor = 0;
  int right_cursor = 0;
  int index_cursor = 0;

  while (left_cursor < left.size() && right_cursor < right.size())
  {
    if (left[left_cursor] > right[right_cursor])
    {
      result[index_cursor++] = right[right_cursor++];
    }
    else
    {
      result[index_cursor++] = left[left_cursor++];
    }
  }

  /* Pushing all the left on left array an right array */
  while (left_cursor < left.size())
  {
    result[index_cursor++] = left[left_cursor++];
  }

  while (right_cursor < right.size())
  {
    result[index_cursor++] = right[right_cursor++];
  }
  for (auto v : result)
  {
    cout << v << " ";
  }
  cout << endl;
  return result;
}

int main()
{
  vector<int> unsorted_to_sorted = {3, 5, 1, 2, 5, 8, 10, 21};
  vector<int> sorted = merge(unsorted_to_sorted);

  for (auto elem : sorted)
  {
    cout << elem << " ";
  }
  cout << endl;
  return 0;
}