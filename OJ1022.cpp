#include <iostream>
using namespace std;
int main() {

    long long int n;
    cin>>n;

    int a = 1;
    int b = 1;
    int tmp;
    long long int t;
    if (n>2040)
        t = n % 2040;
    else
        t = n;
    for (long long int i=2; i<=t-1; i++)
    {
        tmp = b;
        b = (a+ b)%2010;
        a = tmp;

    }
    cout<<b<<endl;

    return 0;
}