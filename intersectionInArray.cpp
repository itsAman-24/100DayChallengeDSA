#include <bits/stdc++.h>
using namespace std;

vector<int> intersectInArray(vector<int> a , vector<int> b) {
    int n1 = a.size();
    int n2 = b.size();

    vector<int> visited (n2 , 0);   // for keeping the track that element is already visited or not
    // int visited[n2];
    vector<int> ans;

    for(int i = 0; i < n1; i++) {
        for(int j = 0; j < n2; j++) {
            if(a[i] == b[j] && visited[j] == 0) {
                ans.push_back(a[i]);
                visited[j] = 1;
                break;
            }

            if(a[i] < b[j]) {  /* while traversing inside second array if any element is greater 
                                  than first array's element then break the loop because (sorted hai array)*/
                break;
            }
        }
    }

    return ans;
}
vector<int> intersectInArrayFunction2(vector<int> a , vector<int> b) {
    int n1 = a.size();
    int n2 = b.size();
    int i = 0;
    int j = 0;
    vector<int> ans;

    if(a[i] < b[j]) i++;
    else j++;

    if(a[i] == b[j]) {
        ans.push_back(a[i]);
        i++;
        j++;
    }
    return ans;
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

    vector<int> c = intersectInArrayFunction2(a,b);
    
    cout << "Intersections inside both the arraya are-> ";
    for(int i = 0; i < c.size(); i++) {
        cout << c[i] << " ";
    }
}