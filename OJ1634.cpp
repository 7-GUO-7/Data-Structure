//#include <iostream>
//using namespace std;
//int count1=0;
//int count2=0;

//void percolateDown(int a[],int hole,int size)
//{
//    int child;
//    int tmp;
//    a[hole]=a[size-1];
//    size--;
//    for (;hole*2+1<size;hole=child)
//    {
//        child=hole *2+1;
//
//        if (child<size-1) {
//            count1++;
//            if (a[child + 1] < a[child]) { child++; }
//
//        }
//        count1++;
//        if (a[child]<a[hole])
//        {tmp=a[hole];
//        a[hole]=a[child];
//        a[child]=tmp;
//        }
//
//        else break;
//
//    }
//}
//
//void heapSort(int a[],int size)
//{
//    int i;
//    int tmp,i1;
//    for (i=1;i<size;++i)
//    {
//        i1=i;

//        while (i1!=0) {
//            if(a[i1]<a[(i1-1)/2]&&++count1)
//            {
//                // if (tmpcount>=1)

//                tmp = a[i1];
//            a[i1] = a[(i1 - 1) / 2];
//            a[(i1 - 1) / 2] = tmp;
//            i1 = (i1 - 1) / 2;

//            }
//            else break;
//        }
//    }
//    int old_size=size;
//    for (i=old_size;i>1;--i)
//    {
//        percolateDown(a,0,size--);
//    }
//}
//
//void merge(int a[],int left,int mid, int right)
//{
//    int *tmp=new int [right-left+1];
//    int i=left,j=mid,k=0;
//
//    while (i<mid &&j<=right) {
//        count2++;
//        if (a[i] < a[j]) tmp[k++] = a[i++];
//        else tmp[k++] = a[j++];
//    }
//    while (i<mid) tmp[k++]=a[i++];
//    while (j<=right) tmp[k++]=a[j++];
//
//    for (i=0,k=left;k<=right;) a[k++]=tmp[i++];
//    delete [] tmp;
//
//}
//
//
//void mergeSort(int a[],int left,int right)
//{
//    int mid=(left+right+1)/2-1;
//    if (left == right) return;
//    mergeSort(a,left,mid);
//    mergeSort(a,mid+1,right);
//    merge(a,left,mid+1,right);
//}
//
//
//int main() {
//    int type,n;
//    cin>>n>>type;
//    if (type==1)
//    {
//        int *data=new int[n];
//        for (int i=0;i<n;++i)
//        {
//            cin>>data[i];
//        }
//        heapSort(data,n);
//        cout<<count1<<endl;
//    }
//
//    if (type==2)
//    {
//        int *data=new int[n];
//        for (int i=0;i<n;++i)
//        {
//            cin>>data[i];
//        }
//        mergeSort(data,0,n-1);
//        cout<<count2<<endl;
//    }
//
//
//
//    return 0;
//}


#include <iostream>

using namespace std;

int c=0;
int cur_size=0;

void _insert(int *&arr,int num){
    int hole = ++cur_size;
    for (; hole>1 &&  ++c &&num<arr[hole/2];hole /= 2)
        arr[hole] = arr[hole/2];
    arr[hole] = num;
}

void percolate(int *&arr,int hole){
    int child;
    int tmp = arr[hole];
    for (;hole*2 <= cur_size;hole = child){
        child = 2*hole;
        if (child!=cur_size and ++c and arr[child+1]<arr[child])
            child++;
        if (++c and arr[child]<tmp)
            arr[hole] = arr[child];
        else
            break;
    }
    arr[hole] = tmp;
}

void del(int *&arr){
    int min_;
    min_ = arr[1];
    arr[1] = arr[cur_size--];
    percolate(arr,1);
}

void merge(int a[], int left, int mid, int right)
{
    int *tmp = new int[right-left+1];
    int i=left, j=mid, k=0;
    while(i<mid && j<=right)
    {
        c++;
        if(a[i] < a[j]) tmp[k++] = a[i++];
        else tmp[k++] = a[j++];
    }
    while(i<mid) tmp[k++] = a[i++];
    while(j<=right) tmp[k++] = a[j++];
    for(i=0, k=left; k<=right;) a[k++] = tmp[i++];
    delete [] tmp;
}

void mergesort(int a[], int left, int right)
{
    int mid = (left+right-1)/2;
    if(left==right) return;
    mergesort(a, left, mid);
    mergesort(a, mid+1, right);
    merge(a, left, mid+1, right);
}

int divide(int a[], int low, int high)
{
    int k = a[low];
    do
    {
        while(low<high && a[high]>k && ++c) {--high;}
        if(low<high) {a[low] = a[high]; ++low;}
        while(low<high && a[low]<k && ++c) {++low;}
        if(low<high) {a[high] = a[low]; --high;}
    }while(low != high);
    a[low] = k;
    return low;
}

void quicksort(int a[], int low, int high)
{
    int mid;
    if(low>=high) return;
    mid = divide(a, low, high);
    quicksort(a, low, mid-1);
    quicksort(a, mid+1, high);
}

int main()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];
    if(k==1)
    {
        int *list = new int[n];
        for (int i=0;i<n;++i) {
            _insert(list, a[i]);
        }
        for (int j=0;j<n;++j)
            del(list);
        cout<<c;
    }
    if(k==2)
    {
        mergesort(a, 0, n-1);
        cout<<c;
    }
    if(k==3)
    {
        quicksort(a, 0, n-1);
        cout<<c;
    }
    return 0;
}
