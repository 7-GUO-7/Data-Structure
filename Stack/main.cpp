#include <iostream>
#include "Stack.h"
using namespace std;
int main() {
    int i;
    link_stack<char> st;
    cout<<st.isEmpty()<<endl;
    st.push('y');
    st.push('t');
    cout<<st.top()<<endl;
    cout<<st.pop()<<endl;
    cout<<st.top()<<endl;
    cout<<st.isEmpty();
    return 0;
}