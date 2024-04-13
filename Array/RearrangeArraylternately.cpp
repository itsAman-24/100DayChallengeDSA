// #include <bits/stdc++.h>
// using namespace std;

// int rearrange(int *arr , int srt , int end) {
//     for(int j = end; j >= srt; j--) {
//         arr[j] = arr[j-1];
//     }

//     arr[srt] = arr[end];
//     srt = srt + 2;

//     rearrange(arr,srt,end);

//     // return arr[];

// }


// int main() {
//     int array[] = {1,2,3,4,5,6,7,8};
//     int start = 0;
//     int end = 7;

//     rearrange(array,start,end);

//     //printing the array

//     for(int i = 0; i <= 7; i++) {
//         cout << array[i] << " ";
//     }
// }


#include <iostream>
using namespace std;

void rearrange(int *arr , int srt , int end) {
    
    if(srt >= end) {
        return;
    }

    int temp = arr[end]; // Store the last element of the array
    for(int j = end; j > srt; j--) {
        arr[j] = arr[j-1];
    }
    arr[srt + 1] = temp; // Insert the stored element at the correct position

    rearrange(arr, srt+2, end);
}

int main() {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int start = 0;
    int end = 7;

    rearrange(array, start, end);

    // Printing the rearranged array
    for(int i = 0; i <= end; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    
    return 0;
}
