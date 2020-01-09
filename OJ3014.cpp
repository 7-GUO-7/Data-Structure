#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {

    int n;
    cin>>n;
    vector <int> array1;
    vector <int> array2;
    int tmp;
    for (int i=0; i<n; i++)
    {
        cin>>tmp;
        array1.push_back(tmp);
    }
    for (int i=0; i<n; i++)
    {
        cin>>tmp;
        array2.push_back(tmp);
    }
    sort(array1.begin(), array1.end());
    sort(array2.begin(), array2.end());
    int sum=0;
    for (int i=0; i<n; i++)
    {
        sum += abs(array1[i] -array2[i]);
    }
    cout<<sum<<endl;
    return 0;
}