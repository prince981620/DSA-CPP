#include <iostream>
#include <queue>
using namespace std;

int main(){
    // max heap creation by default it is a max heap
    // priority_queue<int>pq;

    // min heap creation 
    priority_queue<int, vector<int>, greater<int> >pq;
    pq.push(10);
    pq.push(20);
    pq.push(30);
    pq.push(40);
    pq.push(50);

    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
    
    cout << pq.empty();


}