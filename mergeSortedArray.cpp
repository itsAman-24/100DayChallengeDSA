#include <bits/stdc++.h>
using namespace std;

vector<int> sortedArray(vector<int> a, vector<int> b)
{
    int i = 0;
    int j = 0;

    int m = a.size();
    int n = b.size();

    vector<int> mersedArray;

    while (i < m && j < n)
    {
        if (a[i] <= b[j])
        {
            if (mersedArray.size() == 0 || mersedArray.back() != a[i])
            {
                mersedArray.push_back(a[i]);
            }
            i++;
        }

        else
        {
            if (mersedArray.size() == 0 || mersedArray.back() != b[j])
            {
                mersedArray.push_back(b[j]);
            }
            j++;
        }
    }

    while (i < m)
    {
        if (mersedArray.size() == 0 || mersedArray.back() != a[i])
        {
            mersedArray.push_back(a[i]);
        }
        i++;
    }

    while (j < n)
    {
        if (mersedArray.size() == 0 || mersedArray.back() != b[j])
        {
            mersedArray.push_back(b[j]);
        }
        j++;
    }

    return mersedArray;
}


int main () {
    vector<int> a;
    vector<int> b;

    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.push_back(6);
    a.push_back(7);
    a.push_back(8);

    b.push_back(2);
    b.push_back(4);
    b.push_back(8);
    b.push_back(10);
    b.push_back(11);
    b.push_back(14);

    vector<int> c = sortedArray(a,b);

    for(int i = 0; i < c.size(); i++) {
        cout << c[i] << " ";
    }
}