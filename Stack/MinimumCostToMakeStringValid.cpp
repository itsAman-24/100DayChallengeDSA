//WAP to find out the  Minimum Cost To Make String Valid 
// Problem Link: https://bit.ly/3GAYRr5

#include <bits/stdc++.h> 
using namespace std;

int findMinimumCost(string str) {
  //odd string
  if(str.length() % 2 == 1) {
    return -1;
  }
  
  stack<char> s;
  for(int i = 0; i < str.length(); i++) {
    char ch = str[i];
    
    //ch is having open brace
    if(ch == '{') {
      s.push(ch);
    }
    
    //ch is having closed brace
    else {
      //check if stack have open brace to make the pair with ch or not
      if(!s.empty() && s.top() == '{') {
        s.pop();
      }
      else {
        s.push(ch);
      }
    }
  }

  // it means stack is carring nonvalid braces
  int a = 0; // used for counting open braces
  int b = 0; // used for counting closed braces

  while(!s.empty()) {
    if(s.top() == '{') 
      a++;
    
    else 
      b++;
  
    s.pop();
  }
  int ans = (a+1)/2 + (b+1)/2;
  return ans;
}

int main() {

    string inputString = "{{}}{}{}";
    int result = findMinimumCost(inputString);

    if (result != -1) {
        cout << "Minimum cost to balance the string: " << result << endl;
    } else {
        cout << "The string has an odd length and cannot form valid pairs." << endl;
    }

    return 0;
}