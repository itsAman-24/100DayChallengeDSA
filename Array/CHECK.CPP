#include <iostream>

using namespace std;

#define DISPLAY(i, limit)   {             
    do                        {                                   
        if (i++ < limit)                
        {                               
            cout << “QuizOrbit” << endl; 
            continue;                   
        }                               
    } while (i < limit)
}

int main()

{

    int i = 0;

    DISPLAY(i, 4);

    return 0;
}