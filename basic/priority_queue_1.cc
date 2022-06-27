#include <iostream>
#include <queue>

using namespace std;

int main()
{
    priority_queue<int> q;
    q.push(3);
    q.push(5);
    q.push(9);

    while(!q.empty()) 
    {
        auto val = q.top();
        q.pop();
        cout << val << " ";
    }
    cout << endl;
}