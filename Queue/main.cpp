#include <iostream>
#include "Queue.h"
using namespace std;
int main() {
    link_queue<int> q1;
    q1.enQueue(5);
    q1.enQueue(6);
    cout<<q1.getHead();
    cout<<q1.deQueue();

    cout<<q1.getHead();
    cout<<q1.deQueue();
    cout<<q1.isEmpty()<<endl;
    return 0;
}