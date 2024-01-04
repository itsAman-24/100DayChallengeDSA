#include <bits/stdc++.h> 
using namespace std;

vector<int> rotateArray(vector<int>& arr, int n) {
    int temp = arr[0];
    
    //Shifting all the elements from 1 index to its left side

    for(int i = 1; i < n; i++) {
        arr[i-1] = arr[i];
    }

    //Placing the first element at the last index
    arr[n-1] = temp;

    return arr;
}

int main() {
    vector<int> v;

    v.push_back(4);
    v.push_back(5);
    v.push_back(2);
    v.push_back(8);
    v.push_back(9);
    v.push_back(12);

    int n = v.size();

    rotateArray(v,n);

    cout << "Your array after rotating one index to left side is: " << endl;
    for(int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
}
