#include <iostream>
#include "List.h"
using namespace std;
int main() {
    link_list<int> array1;
    array1.taverse();
    array1.insert(0,6);
    array1.insert(0,4);
    array1.insert(0,2);
    array1.insert(0,7);
    array1.insert(0,5);
    array1.insert(0,3);
    array1.insert(0,1);
    array1.taverse();
    cout<<"no.5 is: "<<array1.visit(5)<<endl;
    cout<<"the length is:"<<array1.length()<<endl;
    array1.insert(5,10);
    array1.taverse();
    cout<<array1.search(6)<<endl;
    cout<<array1.visit(4)<<endl;
    array1.remove(3);
    array1.taverse();
    array1.remove(5);
    array1.taverse();
    array1.clear();
    array1.taverse();
    return 0;
}