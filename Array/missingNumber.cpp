//WAP to find the missing number inside the array of N size the elements will be between 1 - N

#include<bits/stdc++.h>
using namespace std;


// First optimal solution for the problem using Sum formula

// int missingNumber(vector<int>&a, int N) {
//     int total = N*(N+1)/2;
//     int sum = 0;
//     for(int i = 0; i < N-1; i++) {
//         sum += a[i];
//     }

//     return total - sum;
// }




//Second optimal solution for the problem using XOR operations

int missingNumber(vector<int>&a, int N) {
    int xor1 = 0;
    int xor2 = 0;

    //One way to solve the problem is by writing two loops

    // for(int i = 1; i <= N; i++) {
    //     xor1= xor1 ^ i;
    // }

    // for(int j = 0; j < N-1; j++) {
    //     xor2 = xor2 ^ a[j];
    // }

    //Another way is to create a single loop which will do the tasks of both loops

    for(int i = 0; i < N-1; i++) {
        xor2 = xor2 ^ a[i];
        xor1 = xor1 ^ (i+1); // doing the task of first loop
    }

    xor1 = xor1 ^ N;  /* This line will perform the last XOR operation of xor1 with N which
                         is not done by our single loop due to its condition check */
                      

    return xor1 ^ xor2;
}

int main() {
    vector<int> a;

    a.push_back(1);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.push_back(6);

    int n = a.size();

    cout <<"Missing number inside the array is -> " << missingNumber(a,n+1);

}