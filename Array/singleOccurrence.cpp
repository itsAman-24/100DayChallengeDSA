// WAP to find the element with single occurrence inside a sorted the vector or array

#include <bits/stdc++.h>
using namespace std;

// Brute force solution with Time complexity as 0(N) and Space complexity as 0(N)

/* int getSingleElement(vector<int> &arr){
    int n = arr.size();

    //Creating an unordered map
    unordered_map<long long , int> map;

    //Storing the key and value inside the map
    for(int i = 0; i < n; i++) {
        map[arr[i]]++;
    }

    //Iterating through the map to find that single element
    for(auto it:map) {
       if(it.second == 1) {
           return it.first;
       }
    }
} */

// int getSingleElement(vector<int> &arr)
// {
//     int low = 0;
//     int high = arr.size() - 1;
//     int mid;
//     while (low < high)
//     {
//         mid = (low + high) / 2;
//         if (mid % 2 != 0)
//         {
//             mid -= 1;
//         }
//         if (arr[mid] == arr[mid + 1])
//         {
//             low = mid + 2;
//         }
//         else
//         {
//             high = mid;
//         }
//     }

//     return arr[low];
// }

// Optimial solution with Time complexity as 0(N) and Space complexity as 0(1)

int getSingleElement(vector<int> &arr)
{
    int n = arr.size();
    int xorr = 0;

    // Performing xor operation between every element of arr
    for (int i = 0; i < n; i++)
    {
        xorr = xorr ^ arr[i];
    }
    return xorr;
}

int main() {
    vector<int> v;

    v.push_back(0);
    v.push_back(0);
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    v.push_back(7);

    cout << "The single occurrening element is -> " << getSingleElement(v);
}