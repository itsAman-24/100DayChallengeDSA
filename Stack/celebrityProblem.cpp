//WAP to find the celebrity from a party(2D matrix)
//Requirements of celebrity are he shouldn't know anyone and everyone should know him
//if knows him it will be represented as 1 and if doesn't knows him it will be represented as 0
#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    private:
    bool knows(vector<vector<int> >& M, int n, int a, int b) {
        if(M[a][b]==1) 
            return true;
        
        else
            return false;
    }
    
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        
    stack<int> s;
	//put all elements inside the stack
	for(int i = 0; i < n; i++) {
		s.push(i);
	}
    
    //taking two values from stack for comparison
	while(s.size() > 1) {
		int A = s.top();
		s.pop();

		int B = s.top();
		s.pop();
        
        /*if A knows B it means it is not a celebrity so push the B inside 
        stack to check if it is celebrity or not*/
		if(knows(M,n,A,B)) {
			s.push(B);
		}

		else {
			s.push(A);
		}
    }

    //last left element inside stack will be the no. 1 candidate for the celebrity
	//but we have to varify and confirm that the element doesn't knows anyone and everyone knows him
	int ans = s.top();
	
    //checking the row for last element (row will tells us that last element knows anyone or not)
	bool checkRow = false;
	int zeroCount = 0;

	for(int i = 0; i < n; i++) {
		if(M[ans][i] == 0) {
		    zeroCount++;
		}
	}
	// it doesn't knows anyone
	if(zeroCount == n){
	    checkRow = true;
	}
	
	//checking the column (Column will tell us that everyone knows last element or not)
	bool checkCol = false;
	int oneCount = 0;
	
	for(int i = 0; i < n; i++) {
	    if(M[i][ans] == 1) {
	        oneCount++;
	    }
	}
	
	//everyone knows him(celebrity)
	if(oneCount == n-1) {
	    checkCol = true;
	}
	
	//if it matches the requirements of a celebrity return the last element as ans
	if(checkRow == true && checkCol == true) {
	    return ans;
	}
	
	//it doesn't matches the requirements of a celebrity so return -1
	else {
	    return -1;
	}
}
	
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}