//WAP to sort 0s 1s and 2s of array
//Time complexity of sortArray function = O(n), where n is the number of elements inside array or vector 
//Space Complexity of sortArray function = O(1),because no extra space is being used by the function except three pointers which has constant space
#include <bits/stdc++.h> 
using namespace std;

vector<int> sortArray(vector<int>& arr, int n)
{
   int low = 0, mid = 0, high = n-1;

   while(mid<=high) {

       //Putting all 0 on low index side (left hand side)
       if(arr[mid] == 0) {
           swap(arr[low],arr[mid]);
           low++;
           mid++;
        }
        
       //if 1 is at mid index (in center position) then nothing to change simply move mid
       else if(arr[mid] == 1) {
           mid++;
        }

       //Putting all 2 on high index side (right hand side)
       else {
           swap(arr[mid],arr[high]);
           high--; /*here we aren't doing anything with mid because the number we will get
                    at mid after swapping could be any number so
                    we have to again check which number it is (0,1,2) and 
                    perform its respective step by checking conditional statements*/
       }
   }

   return arr;
}

int main() {
    vector<int> v;

    v.push_back(1);
    v.push_back(0);
    v.push_back(2);
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(1);
    v.push_back(0);

    int n = v.size();

    sortArray(v,n);

    cout << "Your array after sorting 0s 1s 2s will look like -> ";

    for(int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
}
