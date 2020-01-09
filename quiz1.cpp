#include <iostream>
using namespace std;
using namespace std;
class Joseph
{
    int n;//person
    int m;//gap
    int c;
public:
    Joseph(int a,int b,int c1);
    void simulate();
};

Joseph::Joseph(int a,int b,int c1)
{
    n=a;m=b;c=c1;
}
struct node
{int data;
    node *next;};

void Joseph::simulate()
{
    int count=1;
    node *head,*p,*q;
    int i;
    int use;
    head=p=new node;
    p->data=0;
    for (i=1;i<n;++i)
    {
        q=new node;
        q->data=i;
        p->next=q;
        p=q;
    }
    p->next=head;
    q=head;
    while (q->next!=q||count==c)
    {
        if (count<=c)
        {for (i=0;i<m-1;++i)
            {
                p=q;q=p->next;
            }
            p->next=q->next;
//            cout<<q->data<<'\t';
            use=q->data;
//            cout<<use<<endl;
            delete q;count++;
            q=p->next;}
            else break;
    }
//    cout<<"\nThe last one is:"<<endl;
//    cout<<q->data<<endl;
    cout<<use+1;
}
int main() {

    int n,m,k;
    cin>>n>>m>>k;
    Joseph obj(n,m,k);
    obj.simulate();

    return 0;
}