#include <iostream>
using namespace std;

class hftree{
public:
    struct node
    {
        int data;
        int weight;
        int parent,left,right;
    };

    node *elem;
    int length;

    hftree(const int *v,const int *w,int size)
    {
        const long MAX_INT=100000000;
        int min1,min2;
        int x,y;
        length=2*size;
        elem=new node [length];
        int i;
        for ( i=size;i<length;++i)
        {
            elem[i].weight=w[i-size];
            elem[i].data=v[i-size];
            elem[i].parent=elem[i].left=elem[i].right=0;
        }

        for (i=size-1;i>0;--i)
        {
            min1=min2=MAX_INT;
            x=y=0;
            for (int j=i+1;j<length;++j)
                if (elem[j].parent==0)
                    if (elem[j].weight<min1)
                    {
                        min2=min1;
                        min1=elem[j].weight;
                        x=y;
                        y=j;
                    }
                    else if (elem[j].weight<min2)
                    {
                        min2=elem[j].weight;
                        x=j;
                    }
            elem[i].weight=min1+min2;
            elem[i].left=x;
            elem[i].right=y;
            elem[i].parent=0;
            elem[x].parent=i;
            elem[y].parent=i;
        }
    }


    void calc()
    {
        long sum=0;
        int size=length/2;
        int p;
        int count;
        for (int i=size;i<length;++i)
        {
            count=0;
            p=elem[i].parent;
            while(p)
            {
                count++;
                p=elem[p].parent;
            }
            sum+=elem[i].weight*count;

        }
        cout<<sum<<endl;
    }
    ~hftree(){delete [] elem;}
};


int main() {
    int n,input;
    cin>>n;
    int *a=new int [n];
    int *w=new int [n];
    for (int i=0;i<n;++i)
    {
        a[i]=i;
        cin>>input;
        w[i]=input;
    }

    hftree tree(a,w,n);
    tree.calc();

    return 0;
}