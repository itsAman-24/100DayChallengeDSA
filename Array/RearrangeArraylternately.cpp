#include <iostream>
using namespace std;

void rearrange(int *arr , int srt , int end) {
    
    if(srt >= end) {
        return;
    }

    int temp = arr[end]; // Store the last element of the array
    for(int j = end; j >= srt; j--) {
        arr[j] = arr[j-1];
    }
    arr[srt] = temp; // Insert the element at the correct position

    rearrange(arr, srt+2, end);
}

int main() {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int start = 0;
    int size = sizeof(array) / sizeof(array[0]);
    int lastIdx = size - 1;


    rearrange(array, start, lastIdx);

    // Printing the rearranged array
    for(int i = 0; i <= lastIdx; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    
    return 0;
}
