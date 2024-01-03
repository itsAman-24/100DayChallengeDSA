//WAP to check wheather the array is sorted or not

#include <bits/stdc++.h>
using namespace std;

bool sortedOrNOt(vector<int> arr , int n) {
    for(int i = 1; i < n; i++) {
        if(arr[i] >= arr[i-1]) {

        }
        else {
            return false;
        }
    }

    return true;
}

int main() {
    vector<int> v;
    v.push_back(3);
    v.push_back(4);
    v.push_back(0);
    v.push_back(6);
    v.push_back(9);
    v.push_back(10);

    int n = v.size();

    bool result = sortedOrNOt(v,n);

    if(result) {
        cout << "It is sorted array" << endl;
    }

    else {
        cout << "It is not a sorted array" << endl;
    }


}