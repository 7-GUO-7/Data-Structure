#include <iostream>
#include <cstring>
using namespace std;


class min_heap{

public:
    int *data;
    int current_size;
    min_heap()
    {
        data=new int [30000];
        for (int i=0;i<30000;++i)
        {data[i]=-1;current_size=0;}

    }
};

void insert(min_heap * & heap, int x) {
    int p, i1, tmp;
    for (p = 1; p < 30000; ++p) {
        if (heap->data[p] == -1)
            break;
    }
    heap->data[p] = x;
    i1 = p;
    while (true) {
        if (i1 / 2 != 0) {
            if (heap->data[i1 / 2] > heap->data[i1]) {
                tmp = heap->data[i1 / 2];
                heap->data[i1 / 2] = heap->data[i1];
                heap->data[i1] = tmp;

            }
            i1 = i1 / 2;
        } else
            break;
    }
    heap->current_size++;
}

int find(min_heap *&heap,int x)
{
    int tmp,min,min_position;
    bool flag=0;
    for (tmp=1;tmp<30000;++tmp) {
        if (heap->data[tmp] == -1)
            break;
        if (heap->data[tmp]>x&&!flag)
        {min=heap->data[tmp];min_position=tmp;flag=1;}
        if (heap->data[tmp]<min&&flag&&heap->data[tmp]>x)
        {min=heap->data[tmp];min_position=tmp;}
    }
    return min_position;
}

void decrease(min_heap *& heap, int to_decrease, int decrease_)
{
    heap->data[to_decrease]-=decrease_;
    int  i1, tmp;

    i1 = to_decrease;
    while (true) {
        if (i1 / 2 != 0) {
            if (heap->data[i1 / 2] > heap->data[i1]) {
                tmp = heap->data[i1 / 2];
                heap->data[i1 / 2] = heap->data[i1];
                heap->data[i1] = tmp;

            }
            i1 = i1 / 2;
        } else
            break;
    }
}
bool isEmpty(min_heap * heap)
{
    return heap->current_size==0;
}

int main() {
    int M;
    char input[30];
    cin >> M;
    int number;
    int to_decrease;
    int decrease_;
    int find_output;
    min_heap *heap;
    heap=new min_heap;
    for (int i = 0; i < M; ++i) {
        cin >> input;
        if (strcmp(input, "insert") == 0) {
            cin >> number;
            insert(heap,number);
        }


        if (strcmp(input, "find") == 0) {
            cin >> number;
            find_output=find(heap,number);
            cout<<find_output<<endl;
        }

        if (strcmp(input, "decrease") == 0) {
            cin>>to_decrease;
            cin>>decrease_;
            decrease(heap,to_decrease,decrease_);
        }

        if (strcmp(input, "isEmpty") == 0) {
            cout<<isEmpty(heap)<<endl;
        }
    }
    return 0;
}