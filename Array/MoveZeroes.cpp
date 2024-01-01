#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int> &nums)
{
    int i = 0;
    int j = 0;

    while (j < nums.size())
    {

        if (nums[j] != 0)
        {
            swap(nums[i], nums[j]);
            i++;
        }
        j++;
    }
}

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(0);
    v.push_back(14);
    v.push_back(3);
    v.push_back(0);

    moveZeroes(v);

    for(int i = 0; i < v.size(); i++) {
        cout << v[i] <<" ";
    }
}


