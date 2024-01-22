//WAP to find the next greater element 

#include <iostream>
#include <algorithm>
using namespace std;

string nextGreater(string S) {
    // Find the first character that is smaller than the character next to it
    int i = S.length() - 2;
    while (i >= 0 && S[i] >= S[i + 1]) {
        i--;
    }

    // If no such character is found, the number is the largest possible permutation
    if (i == -1) {
        return "-1";
    }

    // Find the smallest character to the right of the character found in the previous step
    int j = S.length() - 1;
    while (S[j] <= S[i]) {
        j--;
    }

    // Swap the two characters
    swap(S[i], S[j]);

    // Reverse the substring to the right of the original character
    reverse(S.begin() + i + 1, S.end());

    return S;
}

int main() {
    // Example usage:
    string number = "56789";
    string result = nextGreater(number);

    cout << "Next greater number: " << result << endl;

    return 0;
}
