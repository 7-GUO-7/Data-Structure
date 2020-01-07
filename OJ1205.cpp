#include <iostream>
using namespace std;
long long int ackerman(int m,int n)
{
    if (m==0) return n+1;
    if (m!=0 && n==0) return ackerman(m-1,1);
    if ((m!=0 && n!=0)) return ackerman(m-1,ackerman(m,n-1));
}

int main() {
    int m,n;
    cin>>m>>n;
    cout<<ackerman(m,n)<<endl;
    return 0;
}