//WAP to rotate the array elements to left side by one place

#include <bits/stdc++.h>
using namespace std;

vector<int> rotateByOne(vector<int> &arr, int n) {
    int temp = arr[0];  // storing the first element inside temp variable

    for(int i = 1; i < n; i++) {
        arr[i-1] = arr[i];
    }

    arr[n-1] = temp;   // Placing the first element at last index

    return arr;
}

int main() {
    vector<int> v;
    v.push_back(4);
    v.push_back(2);
    v.push_back(6);
    v.push_back(8);
    v.push_back(9);
    v.push_back(0);

    int n = v.size();

    rotateByOne(v,n);
    
    cout << "Your array after rotating to left by one will look like ->  ";
    for(int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
}