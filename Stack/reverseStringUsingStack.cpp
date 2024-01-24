//WAP to reverse a string using a stack

#include <iostream>
#include <stack>
#include <cstring>

char* reverse(char *S, int len)
{
    std::stack<char> st;
    
    for(int k = 0; k < len; k++) {
        st.push(S[k]);
    }

    char *str = new char[len + 1];  // +1 for the null terminator
    int i = 0;

    while (!st.empty()) {
        str[i++] = st.top();
        st.pop();
    }

    str[i] = '\0';
    return str;
}

int main() {
    char input[] = "Hello, World!";
    int len = strlen(input);

    char *reversed = reverse(input, len);

    std::cout << "Original string : " << input << std::endl;
    std::cout << "Reversed string : " << reversed << std::endl;

    // Don't forget to free the allocated memory
    delete[] reversed;

    return 0;
}
