// WAP to find the maximum count for consecutive ones (The array or vector should be binary array or vector means elements should be only 0 and 1)

#include<bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int maxi = 0;
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
        {
            count++;
            maxi = max(maxi, count);
        }
        else
        {
            count = 0;
        }
    }
    return maxi;
}

int main() {
    vector<int> v;
    
    v.push_back(0);
    v.push_back(1);
    v.push_back(1);
    v.push_back(0);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);

    cout << "The maximum count for consecutive Ones is -> " << findMaxConsecutiveOnes(v);

}
