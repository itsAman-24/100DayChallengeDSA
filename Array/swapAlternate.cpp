#include <bits/stdc++.h>
using namespace std;

void swapAlternate(int *arr, int srt, int endIdx) {
    for(int i = 0; i < endIdx; i=i+2) {
        swap(arr[i],arr[i+1]);
    }
}

int main() {
    int arr[] = {4,5,6,2,9,13,7,0};
    int size = sizeof(arr) / sizeof(arr[0]);
    int endIndex = size - 1;

    swapAlternate(arr,0,endIndex);

    for(int i = 0; i <= endIndex; i++) {
        cout << arr[i] << " ";
    }
    
}