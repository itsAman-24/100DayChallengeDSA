//WAP to check if it is a valid parentheses or not  (using stack)

#include <bits/stdc++.h>
using namespace std;

bool isValidParenthesis(string s)
{
   stack<int> st;

   for(int i=0; i < s.size(); i++) {
       char ch = s[i];

       //checking that Parentheses is opening or closing 
       if(ch == '(' || ch == '{' || ch == '[') {
           st.push(ch);
     
       }

       else {
           // it is a closing Parentheses
           if(!st.empty()) {
               
               char top = st.top();

               if( (ch==')' && top=='(') ||
                   (ch=='}' && top=='{') || 
                   (ch==']' && top=='[')   ) {
                       st.pop();
                   }

                else {
                    return false;
                }
            }

           else {
                return false;
            }
       }

   }

   if(st.empty()) 
           return true;
       
   else
           return false;
       
}

int main() {

   string input = "{ [(]] }";
    if (isValidParenthesis(input)) {
        cout << "The parentheses are valid." << endl;
    } else {
        cout << "The parentheses are not valid." << endl;
    }

    return 0;
} 


/* The code uses a stack data structure to check if a given string of parentheses is valid or not. The basic idea is to iterate through the string, and every time an opening parenthesis is encountered, it is pushed onto the stack. When a closing parenthesis is encountered, the code checks if there is a corresponding opening parenthesis at the top of the stack. If there is, it means that the parentheses are properly nested, and the opening parenthesis is popped from the stack. If not, or if there is no opening parenthesis in the stack when a closing parenthesis is found, the string is considered invalid.


Here's a step-by-step breakdown:

Initialize an empty stack to keep track of opening parentheses.

Iterate through each character in the input string.

If the character is an opening parenthesis ('(', '{', '['), push it onto the stack.

If the character is a closing parenthesis (')', '}', ']'), check if the stack is not empty. If it's not empty, pop the top element from the stack and check if it matches the corresponding opening parenthesis for the current closing parenthesis. If it matches, continue; otherwise, return false.

If the stack is empty after processing all characters, return true; otherwise, return false.  */
