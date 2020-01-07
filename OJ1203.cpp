#include <iostream>
using namespace std;

void list_int();
void list_char();
void list_double();


template <class elemType>
class seqlist
{
    int currentlength;
    int max_size;
    elemType *p;
public:
    seqlist(int ms=0);
    seqlist(const seqlist &sl);
    void l_insert(elemType x);
    void l_traverse();
    seqlist operator+(const seqlist &s1)const;
    seqlist &operator=(const seqlist &s);
    ~seqlist(){delete []p;}
};

int main()
{
    char ch[10];
    cin>>ch;
//    cin.clear();
//    cin.sync();
    switch (ch[0])
    {
        case 'i':
            list_int();
            break;
        case 'c':
            list_char();
            break;
        case 'd':
            list_double();
            break;
    }
}

void list_int()
{
    int len_a,len_b;
    cin>>len_a>>len_b;
//    cin.clear();
//    cin.sync();
    seqlist<int> a(len_a);
    seqlist<int> b(len_b);
    int x;
    for(int i=1;i<=len_a;i++)
    {
        cin>>x;
        a.l_insert(x);
    }
    for(int i=0;i<len_b;i++)
    {
        cin>>x;
        b.l_insert(x);
    }
    seqlist<int> c(len_a+len_b);
    c=a+b;
    c.l_traverse();
}

void list_char()
{
    int len_a,len_b;
    cin>>len_a>>len_b;
    seqlist<char> a(len_a);
    seqlist<char> b(len_b);
    char x;
    for(int i=1;i<=len_a;i++)
    {
        cin>>x;
        a.l_insert(x);
    }
    for(int i=0;i<len_b;i++)
    {
        cin>>x;
        b.l_insert(x);
    }
    seqlist<char> c(len_a+len_b);
    c=a+b;
    c.l_traverse();
}

void list_double()
{
    int len_a,len_b;
    cin>>len_a>>len_b;
    seqlist<double> a(len_a);
    seqlist<double> b(len_b);
    double x;
    for(int i=1;i<=len_a;i++)
    {
        cin>>x;
        a.l_insert(x);
    }
    for(int i=0;i<len_b;i++)
    {
        cin>>x;
        b.l_insert(x);
    }
    seqlist<double> c(len_a+len_b);
    c=a+b;
    c.l_traverse();
}

template <class elemType>
seqlist<elemType>::seqlist(int ms)
{
    currentlength=0;
    max_size=ms;
    p=new elemType[max_size];
}

template <class elemType>
seqlist<elemType>::seqlist(const seqlist<elemType> &s1)
{
    currentlength=s1.currentlength;
    max_size=s1.max_size;
    p=new elemType[max_size];
    for(int i=0;i<currentlength;i++) *(p+i)=*(s1.p+i);
}

template <class elemType>
void seqlist<elemType>::l_insert(elemType x)
{
    *(p+currentlength)=x;
    currentlength++;
}

template <class elemType>
void seqlist<elemType>::l_traverse()
{
    for(int i=0;i<currentlength;i++) cout<<*(p+i)<<" ";
    cout<<endl;
}

template <class elemType>
seqlist<elemType> seqlist<elemType>::operator+(const seqlist<elemType> &s1)const
{
    seqlist tmp;
    tmp.max_size = max_size+s1.max_size;
    tmp.p=new elemType[tmp.max_size];
    tmp.currentlength = currentlength+s1.currentlength;
    for(int i=0;i<currentlength;i++) *(tmp.p+i)=*(p+i);
    for(int i=0;i<s1.currentlength;i++) *(tmp.p+currentlength+i)=*(s1.p+i);
    return tmp;
}

template <class elemType>
seqlist<elemType> &seqlist<elemType>::operator=(const seqlist<elemType> &s1)
{
    if(this==&s1) return *this;
    delete []p;
    max_size=s1.max_size;
    currentlength=s1.currentlength;
    p=new elemType[currentlength];
    for(int i=0;i<currentlength;i++) *(p+i)=*(s1.p+i);
    return *this;
}
