#include <iostream>
using namespace std;
int divide(int *a, int low,int high)
{
    int k=a[low];
    do{
        while(low<high && a[high]>k) --high;
        if (low<high) {a[low]=a[high];++low;}
        while (low<high && a[low]<=k) ++low;
        if (low<high) {a[high]=a[low];--high;}
    }while (low!=high);
    a[low]=k;
    return low;
}

void QuickSort(int * a ,int low, int high)
{
    int mid;
    if (low>=high) return;
    mid=divide(a,low,high);
    QuickSort(a,low,mid-1);
    QuickSort(a,mid+1,high);
}

int num[1000000];
int main() {

    int n,input;
    cin>>n;
    int i;
    for (i=0;i<n;++i)
    {
        cin>>input;
        num[i]=input;
    }


    QuickSort(num,0,i-1);

    int count=1;
    int front;
    front=num[0];
    for (i=0;i<n;++i)
        if (num[i]!=front)
        {
            count++; front=num[i];
        }


    cout<<count<<endl;
    return 0;
}