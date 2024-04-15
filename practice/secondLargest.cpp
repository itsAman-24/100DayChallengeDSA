#include<bits/stdc++.h>
using namespace std;

int findSecondLargest(int *arr, int size) {
    int largest = arr[0];
    int smallest = INT_MAX;

    for(int i = 1; i < size; i++) {
        if(arr[i] > largest) {
            smallest = largest;
            largest = arr[i];
        }

        if(arr[i] < largest && arr[i] > smallest) {
            smallest = arr[i];
        }
    }

    if(smallest == INT_MAX) {
        cout <<"Error in the input" << endl;
    }

    else {
        cout << "The first and second Largest elements are: " << largest << "  " << smallest << endl;
    }
}

int main() {
    int arr[] = {2,56,12,5,8};
    int length = sizeof(arr) / sizeof(arr[0]);
    int size = length - 1;

    findSecondLargest(arr,size); 
}