//WAP to reverse the queue

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    queue<int> rev(queue<int> q)
    {
        stack<int> s;

        while (!q.empty())
        {
            int element = q.front();
            q.pop();
            s.push(element);
        }

        while (!s.empty())
        {
            int element = s.top();
            s.pop();
            q.push(element);
        }

        return q;
    }
};

int main()
{
    // Example usage
    queue<int> originalQueue;
    for (int i = 1; i <= 5; ++i)
    {
        originalQueue.push(i);
    }

    Solution solution;
    queue<int> reversedQueue = solution.rev(originalQueue);

    // Display original and reversed queues
    cout << "Original Queue: ";
    while (!originalQueue.empty())
    {
        cout << originalQueue.front() << " ";
        originalQueue.pop();
    }

    cout << "\nReversed Queue: ";
    while (!reversedQueue.empty())
    {
        cout << reversedQueue.front() << " ";
        reversedQueue.pop();
    }

    return 0;
}
