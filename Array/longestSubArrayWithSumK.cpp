//WAP to find the longest subarray with sum K

#include <bits/stdc++.h>
using namespace std;
int LongSubArraySum(vector<int> v1, long long k) {
    long long sum = 0;
    int maxLength = 0;

    map<long long ,int> subArraySum;

    for(int i=0; i<v1.size(); i++) {
        sum += v1[i];

        if(sum == k) {
            maxLength = max(maxLength, i+1);
        }

        int rem = sum - k;
        if(subArraySum.find(rem) != subArraySum.end()) {
            int length = i - subArraySum[rem];
            maxLength = max(maxLength, length);

        }

        if(subArraySum.find(sum) == subArraySum.end()) {
        subArraySum[sum] = i;
        }
 
}
      
  
    return maxLength;


}


int main() {
    vector<int> vec;
    // vec.push_back(1);
    // vec.push_back(5);
    // vec.push_back(3);
    // vec.push_back(8);
    // vec.push_back(1);
    // vec.push_back(1);
    // vec.push_back(6);
    // vec.push_back(4);
    vec.push_back(2);
    vec.push_back(0);
    vec.push_back(0);
    vec.push_back(0);
    vec.push_back(3);

   cout <<"The longest subarray with sum as K is of " << LongSubArraySum(vec,3) << " elements" << endl;


}
