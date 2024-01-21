// WAP to find the two sum with target K

#include<bits/stdc++.h>
using namespace std;

//BruteForce solution

/* bool findTwoSum(vector<int> arr, int target) {
    int n = arr.size();

    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum = sum + arr[j];
            if(sum == target) {
                cout << arr[i] <<" "<< arr[j] <<endl;
                return true;
                break;
            }
        }
    }
    return false;
} */

//Better solution by using map

pair<int,int> findTwoSum(vector<int> arr,int target) {
    int n = arr.size();
    map<int,int> mapp;

    for(int i = 0; i < n; i++) {
        int a = arr[i];
        int more = target - a;
        
        if(mapp.find(more) != mapp.end()) {

            return make_pair(i, mapp[more]);
        }
        mapp[a] = i;
    }
    throw runtime_error("No pair found");
}

string checkTwoSum(vector<int> book, int target)
{
   int n = book.size();
   int start = 0;
   int end = n-1;

   //Sorting the vector
   sort(book.begin(),book.end());

   while(start < end) {
       int sum = book[start] + book[end];
       if(sum == target) {
           return "YES";
       }

       else if(sum < target) start++;

       else end--;
    }

   return "NO";
}



int main() {
    vector<int> v;

    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(3);
    v.push_back(9);
    v.push_back(1);

    int k;
    cout << "Enter the value of target as K" << endl;
    cin >> k;
    
   // cout << "The two elements having the target are -> ";
    
    // bool result = findTwoSum(v,k);
    // if(result) {

    // }

    // else {
    //     cout << "No element is present with sum as K" << endl;
    // }
    
   /*try {
        pair<int, int> result = findTwoSum(v, k);
        cout << "Indexs : " << result.first << " and " << result.second << endl;
    } catch (const runtime_error& e) {
        cout << "No element is present with sum as K" << endl;
    } */

    cout << checkTwoSum(v,k) << " elements are there for Two Sum";

    return 0;
}