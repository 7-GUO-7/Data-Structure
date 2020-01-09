#include <iostream>
#include <iostream>
using namespace std;

void simpleInsertSort(int a[], int size) //直接插入排序
{    int k;
    int tmp;
    for (int j=1; j<size; ++j) {
        tmp = a[j];
        for ( k = j-1; tmp < a[k] && k >= 0; --k)
            a[k+1] = a[k];
        a[k+1] = tmp;
    }
}

void BInsertionSort(int a[],int n) //二分插入排序
{
    int tmp,low,high,mid;
    for(int i=1; i<n;++i){
        tmp = a[i];
        for(low = 0,high = i-1;high>=low;){
            mid = (low+high)/2;
            if(tmp<a[mid])
                high = mid -1;
            else
                low = mid+1;
        }
        for (int j=i-1;j>=low;j--)
            a[j+1] = a[j];
        a[low] = tmp;
    }
}

void shellSort(int a[], int size) //希尔排序
{
    int step, i, j;
    int tmp;
    for (step = size/2; step > 0; step /= 2)     //step为希尔增量
        for (i = step; i < size; ++i) {
            tmp = a[i];
            for (j = i - step; j >= 0 && a[j] > tmp;  j -= step)
                a[j+step] = a[j];
            a[j+step] = tmp;
        }
}

void simpleSelectSort(int a[], int size) //选择排序
{
    int  i, j, min;
    int tmp;
    for (i = 0; i < size -1; ++i) {
        min = i;
        for (j = i+1; j < size; ++j)
            if (a[j] < a[min]) min = j;
        tmp = a[i]; a[i] = a[min]; a[min] = tmp;
    }
}



void percolateDown(int a[], int hole, int size )
{
    int child;
    int tmp = a[ hole ];
    for( ; hole * 2 + 1 < size; hole = child )	 {
        child = hole * 2 + 1;
        if( child != size - 1 && a[ child + 1 ] > a[ child ] )
            child++;
        if( a[ child ] > tmp )   a[ hole ] = a[ child ];
        else    break;
    }
    a[ hole ] = tmp;
}

void heapSort(int a[], int size)
{
    int  i;
    int tmp;
    // 创建初始的堆
    for(  i = size / 2 - 1; i >= 0; i-- )
        percolateDown( a, i, size );
    //执行n-1次deQueue
    for ( i = size - 1; i > 0; --i) {
        tmp = a[0]; a[0] = a[i]; a[i] = tmp;       //delete  a[0]
        percolateDown( a, 0, i );
    }
}

int divide( int a [], int low, int high)
{
    int  k = a[low];
    do  {
        while (low < high && a[high] >= k)
            --high;
        if (low < high){
            a[low] = a[high];
            ++low;
        }
        while (low < high && a[low] <= k)
            ++low;
        if (low < high) {
            a[high] = a[low];
            --high;
        }
    } while (low != high);
    a[low] = k;
    return low;
}
void quickSort(int a [] , int low, int high) //快速排序
{
    int mid;
    if (low >= high) return;
    mid = divide(a, low, high);
    quickSort( a, low, mid-1);//排序左一半
    quickSort( a, mid+1, high);//排序右一半
}

void merge(int a [], int left, int mid, int right)
{
    int *tmp = new int[right-left+1];
    int i= left, j = mid, k = 0;
    while (i < mid && j <= right)   {
        if (a[i] < a[j])     tmp[k++] = a[i++];
        else tmp[k++] = a[j++];}
    while ( i<mid ) tmp[k++] = a[i++];       //前半部分没有结束
    while ( j<=right ) tmp[k++] = a[j++];    //后半部分没有结束

    for (i=0, k = left; k<=right; ) a[k++] = tmp[i++];
    delete [] tmp;
}

void mergeSort(int a[], int left, int right) //归并排序
{
    int mid = (left+right-1)/2;//int mid = (left+right)/2
    if (left == right)
        return;
    mergeSort(a, left, mid);
    mergeSort(a, mid+1, right);
    merge(a,left,mid+1,right);
}

struct node {   //基数排序
    int data;
    node *next;
    node() { next = NULL; }
    node(int d): data(d)
    { next = NULL; }
};

void bucketSort(node *&p)                // p是链表头
{
    node *bucket[10], *last[10], *tail ;
    int i, j, k, base = 1, max = 0, len = 0;
    for (tail = p; tail != NULL; tail = tail->next)        // 找最大键值
        if (tail->data > max)
            max = tail->data;

    // 寻找最大键值的位数为len
    if (max == 0)
        len = 0;
    else
        while (max > 0){
            ++len;
            max /= 10;
        }
    for (i = 1; i <= len; ++i) {                 // 执行len次的分配与重组
        for (j = 0; j <= 9; ++j)
            bucket[j] = last[j] = NULL;
        while (p != NULL) {                                  // 执行一次分配
            k = p->data / base % 10;
            if (bucket[k] == NULL)
                bucket[k] = last[k] = p;
            else
                last[k] = last[k]->next = p;
            p = p->next;
        }
        p = NULL;                                             // 重组后的链表头
        for (j = 0; j <= 9; ++j) {                                  // 执行重组
            if (bucket[j] == NULL)
                continue;
            if (p == NULL)
                p = bucket[j];
            else
                tail->next = bucket[j];
            tail = last[j];
        }
        tail->next = NULL;                   // 表尾置空
        base *= 10;                          // 为下一次分配做准备
    }
}



int main() {
    int a[10]={3,5,1,6,2,2,7,8,9,0}, b[10] = {3,5,1,6,2,7,8,9,2,4};

    quickSort(a,0,9);
//    for(int k = 0;k<10;++k)
//        cout<<a[k]<<" ";

    node *head= new node (10);
    node *t=head;
    for (int i=0;i<10;++i)
    {

        node *p=new node(a[i]);
        t->next=p;
        t=t->next;
    }

    bucketSort(head);
    for (int i=0;i<11;++i)
    {
        cout<<head->data<<' ';
        head=head->next;
    }
//    BInsertionSort(a,10);
//    for(int k = 0;k<10;++k)
//        cout<<a[k]<<" ";
//    cout<<endl;
//    for(int k=0;k<10;++k)
//        cout<<b[k]<<" ";
//    cout<<endl;
//    simpleSelectSort(b,10);
//    for(int k=0;k<10;++k)
//        cout<<b[k]<<" ";
    return 0;
}
