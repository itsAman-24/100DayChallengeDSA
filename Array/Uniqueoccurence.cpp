#include <bits/stdc++.h>
using namespace std;


bool uniqueOccurrences(vector <int> &arr) {
    unordered_map<int, int> mp;

    // stores the frequency
    for (auto num : arr)
    {
        mp[num]++;
    }

    // check the count and insert in unordered set
    unordered_set<int> set;

    for (auto it : mp)
    {
        int freq = it.second;    // it.first -> it points to key 
        set.insert(freq);        // it.second -> it points to value 
    }

    // if size of mp is equalsize of set then it means all have unique occurance

    return set.size() == mp.size();
    
}

  int main()
  {

    vector <int> arr;

    arr.push_back(7);
    arr.push_back(1);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(5);
    arr.push_back(2);

    
    bool result = uniqueOccurrences(arr);

    if(result) {
        cout << "This array has unique occurance " << endl;
    }

    else {
        cout << "This array has no unique occurance " << endl;
    }

    
    return 0;

  }
