#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {

    int n;
    cin>>n;
    int tmp;
    vector <int> array1;
    for (int i=0; i<n; i++)
    {
        cin>>tmp;
        array1.push_back(tmp);
    }
    int profit=0;
    for(int i = 1;i<n;i++){
        int tmp_dif = array1[i]-array1[i-1];
        if(tmp_dif > 0)
            profit += tmp_dif;
    }

    cout<<profit<<endl;
}