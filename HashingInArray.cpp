#include<bits/stdc++.h>
using namespace std;



int main() {
 
   int array[6] = {1,5,3,6,1,0};
   
   //Hashing the values of array in a hash array
   int size;
   cout << "Enter the size of hash array . Remember that the size shouble be less OR equal to the size of original Array" << endl;
   cin >> size;

   int hash[size] = {0};    
   for(int i = 0; i < size; i++) {
      hash[array[i]] += 1;
   }
   

   int num;
   cout << "Enter how many numbers you want to check " << endl;
   cin >> num;

   for(int i = 0; i < num; i++) {
        int values;
        cin >> values;

        if(values >= size) {
        cout << values << " comes 0 times in the array" << endl;  
        exit;
        }
        
        else {
        cout << values << " comes " << hash[values] << " times in the array" << endl;
        }

    }





}