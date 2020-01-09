#include <iostream>
#include <cstring>
using namespace std;
//class string_{
//public:
//    char *data;
//    string_(char *b="")
//    {
//        data=new char[1000];
//        strcpy(data,b);
//    }
//    operator
//};
class hftree{
public:
    struct node
    {
        char data;
        int weight;
        int parent,left,right;
    };

    node *elem;
    int length;

    class hfcode{
    public:
        char data;
        char *code;
        hfcode()
        {
            code=new char[1000];
        }
    };

    hftree(const char *v,const int *w,int size)
    {
        const int MAX_INT=32767;
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

    void getCode( hfcode result[])
    {
        int size=length/2;
        int p,s;
        for (int i=size;i<length;++i)
        {
            result[i-size].data=elem[i].data;
            strcpy(result[i-size].code,"");
            p=elem[i].parent;s=i;
            while (p)
            {
                char *t=new char[1000];
                char *f=new char[1000];
                strcpy(f,"0");
                strcpy(t,"1");
                if (elem[p].left==s)
                    strcpy(result [i-size].code,strcat(f,result[i-size].code));
                else
                    strcpy(result [i-size].code,strcat(t,result[i-size].code));
                s=p;
                p=elem[p].parent;
            }
        }
    }
    ~hftree(){delete [] elem;}
};




int main() {
    char ch[]={"aeistdn"};//所有元素
    int w[]={10,15,12,3,4,13,1};//对应权值
    hftree tree(ch,w,7);
    hftree::hfcode result[7];
    tree.getCode(result);
    for (int i=0;i<7;++i)
        cout<<result[i].data<<' '<<result[i].code<<endl;
    return 0;
}