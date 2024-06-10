#include <iostream>

#include <bits/stdc++.h>
using namespace std;

void _get_input(int &test_case, vector<int> &data)
{
    cin >> test_case;
    while (test_case)
    {
        int tmp;
        cin >> tmp;
        data.push_back(tmp);
        test_case--;
    }
}

int _binary_search(vector<int> _vt, int low, int high, int val)
{
    /* If val is highest -> pushing new value so return - 1*/
    if (val > _vt[high])
    {
        return -1;
    }
    int min_dis = INT32_MAX;

    while (low < high)
    {
        int middle = low + ((high - low) / 2);
        if (_vt[middle] == val)
        {
            return middle;
        }

        if (_vt[middle] < val)
        {
            low = middle + 1;
        }
        else
        {
            high = middle - 1;
        }
    }

    return high == -1 ? low : ((_vt[low] - val) < (_vt[high] - val) ? low : high);
}

int handle_cubeland(vector<int> cubes)
{
    vector<int> cubeland;
    for (auto elem : cubes)
    {
        if (cubeland.empty())
        {
            cubeland.push_back(elem);
        }
        else
        {
            int min_dis = INT32_MAX;
            int min_idx = _binary_search(cubeland, 0, cubeland.size() - 1, elem);
            // cout << elem << " min-idx: " << min_idx << endl;
            if (min_idx == -1)
            {
                cubeland.push_back(elem);
            }
            else
            {
                cubeland[min_idx] = elem;
            }
            /* print cube land */
            for (int i = 0; i < cubeland.size(); ++i)
            {
                cout << cubeland[i] << " ";
            }
            cout << endl;
        }
    }
    return cubeland.size();
}

int main()
{
    int _input;
    vector<int> _data;
    _get_input(_input, _data);
    cout << handle_cubeland(_data) << endl;
    return 0;
}