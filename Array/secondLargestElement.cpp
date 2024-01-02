/*Write a code to find the largest and second largest element in the array*/

#include <bits/stdc++.h>
using namespace std;

int findSecondLargest(int n, vector<int> &arr)
{
    int largest = arr[0];
    int smallest = INT_MAX; // Initialize smallest to a large positive value

    for(int i = 1; i < n; i++) {
        if(arr[i] > largest) {
            smallest = largest;
            largest = arr[i];
        }

        if(arr[i] < largest && arr[i] > smallest) {
            smallest = arr[i];
        }
    }

    // Check if all elements are the same
    if (smallest == INT_MAX) {
        return -1;
    }

    // return smallest;
    return largest;
}

int main() {
    vector<int> v;

    v.push_back(5);
    v.push_back(3);
    v.push_back(4);
    v.push_back(7);
    v.push_back(-1);
    v.push_back(-36);

    int n = v.size();

    // cout <<"The second largest element is: " << findSecondLargest(n,v);
    cout <<"The largest element is: " << findSecondLargest(n,v);

}
