#include <iostream>
using namespace std;
class MYlist{
public:
    int count;
    int *num;
    MYlist()
    {
        count=0;num=new int [1000];
    }
    void append(int x)
    {
        num[count]=x;
        count++;
    }
    bool find(int x)
    {
        for (int i=0;i<count;++i)
        {
            if (num[i]==x)
                return 1;
        }
        return 0;
    }

    bool find(int a,int b)
    {
        for (int i=0;i<count;++i)
        {
            if (num[i]==a)
                if (num[i+1]==b)
                    if (i%2==0)
                        return 1;
        }
        return 0;
    }
};

class linkgraph{
public:
    struct edgenode{
        int end;
        edgenode * next;
        edgenode (int e,edgenode*n=NULL)
        {
            end=e;next=n;
        }
    };

    struct firstnode{
        int ver;
        edgenode *head;
        int edges;
        firstnode(edgenode *h=NULL)
        {
            head=h;edges=0;
        }
    };

    firstnode *list;

    linkgraph(int vsize)
    {
        list=new firstnode[vsize+1];
        for (int i=1;i<vsize+1;++i)
        {
            list[i].ver=i;
        }
    }

    void insert(int a,int b)
    {
        list[a].head=new edgenode(b,list[a].head);
        list[a].edges++;
    }

    bool edge_search(int a,int b)
    {
        edgenode *tmp=list[a].head;
        while(tmp!=NULL)
        {
            if (tmp->end==b)
                return 1;
            tmp=tmp->next;
        }
        return 0;
    }
};

int record[1000]={0};
int record_data[1000]={0};
int record_num=0;
int dfs_count=0;


void dfs(linkgraph &graph,int start,int n)
{
    record[start]=1;
    record_data[record_num]=start;
    record_num++;
    if (record_num==n+1)
    {
        dfs_count++;
        record[start]=0;
        record_num--;
    }

    else {
        linkgraph::edgenode *p=graph.list[start].head;
        while (p!=NULL) {
            if (p->end) {
                if (!record[p->end]) {
                    dfs(graph, p->end, n);
                }
                p = p->next;
            }
        }
        record[start] = 0;record_num--;record_data[record_num]=0;
    }
}


int main() {
    int n,m,start,M,a,b;
    cin>>n>>m>>start>>M;
    linkgraph graph1(n);
    MYlist list1;
    for (int i=0;i<m;++i)
    {
        cin>>a>>b;
        if (!list1.find(a,b))
        {
            list1.append(a);
            list1.append(b);
        }
    }

    for (int i=0;i<list1.count-1;i+=2)
    {
        a=list1.num[i];
        b=list1.num[i+1];
        graph1.insert(a,b);
    }
    dfs(graph1,start,M);
    cout<<dfs_count;
    return 0;
}