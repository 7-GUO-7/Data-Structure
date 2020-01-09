#include <iostream>
using namespace std;




int main() {
    int n,m,count=0;
    int j;
    cin>>n>>m;
    int *input_array;
    input_array=new int[m+10];
//    link_queue<int> q1;


    int i=0,t;
    int sum=0,averange;
    for (i=1;i<=m;++i)

    {
        cin>>input_array[i];
        if (count<n)
        {
            count++;
            sum=0;
            for (j=1;j<=count;++j)
                sum+=input_array[j];
            averange=sum/count;
            cout<<averange<<' ';
        }
        else
        {

//            t=input_array[i-n];
            sum=0;
            for (j=i-n+1;j<=i;++j)
                sum+=input_array[j];
//            sum=sum;
            averange=sum/n;
            cout<<averange<<' ';
        }


    }

    return 0;
}