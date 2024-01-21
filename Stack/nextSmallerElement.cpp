/*WAP to find the next smallest element of vector's element  ans return a vector<int> ans containing 
the next smallest element for each and every element*/

#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);

    vector<int> ans(n);

    for(int i = n-1; i >= 0; i--) {
        int element = arr[i];
        while(s.top() >= element) {
            s.pop();
        }
        ans[i] = s.top();
        s.push(element);
    }
    return ans;
}

int main() {

    vector<int> arr = {4, 5, 2, 10, 8};
    int n = arr.size();

    vector<int> result = nextSmallerElement(arr, n);

    cout << "Next Smaller Elements: ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}