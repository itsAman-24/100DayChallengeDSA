#include <bits/stdc++.h>
using namespace std;

vector<int> rotateArr(vector<int> &arr, int d, int n){
       d = d % n;
       
       int temp[d];
        for(int i = 0; i < d; i++) {
            temp[i] = arr[i];
        }
        
        for(int i = d; i < n; i++) {
            arr[i-d] = arr[i];
        }
        
        //We can also use j = 0 to put temp arr element inside actual array and then j++
        
        for(int i = n-d; i < n; i++) {
            arr[i] = temp[i-(n-d)];
        }

        return arr;
    }

int main() {
    vector<int> v;

    v.push_back(4);
    v.push_back(5);
    v.push_back(2);
    v.push_back(8);
    v.push_back(9);
    v.push_back(4);

    int n = v.size();

    int d;
    cout << "Enter the value of d: " << endl;
    cin >> d;

    rotateArr(v,d,n);

    cout << "Your array after rotating " << d << " indexs to left side is: " << endl;
    for(int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
}