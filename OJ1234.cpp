//#include <iostream>
//#include <queue>
//using namespace std;
//class DisjoinSet{
//private:
//    int size_;
//    int *parent;
//public:
//    DisjoinSet(int s)
//    {
//        size_=s;
//        parent=new int [size_];
//        for (int i=0;i<size_;++i)
//            parent[i]=-1;
//    }
//
//    ~DisjoinSet()
//    {
////        cout<<"1delete set";
////        delete [] parent;
//
//    }
//
//    void Union(int root1,int root2)
//    {
//        if (root1==root2) return;
//        if (parent[root1]>parent[root2])
//        {
//            parent[root2]+=parent[root1];
//            parent[root1]=root2;
//        }
//        else
//        {
//            parent[root1]+=parent[root2];
//            parent[root2]=root1;
//        }
//    }
//
//    int find(int x)
//    {
//        if (parent[x]<0)
//            return x;
//        do{
//            x=parent[x];}
//        while (parent[x]>=0);
//        return x;
//    }
//};
//
//
//template <class T>
//class priorityQueue{
//    int currentsize_;
//    T *Array;
//
//public:
//    priorityQueue(int c=2000000)
//    {
//        Array=new T [c];
//        currentsize_=0;
//    }
//    bool isEmpty() const
//    {
//        return currentsize_==0;
//    }
//    void enqueue(const T & x)
//    {
//        int hole=++currentsize_;
//        for (;hole>1&&x<Array[hole/2];hole/=2)
//            Array[hole]=Array[hole/2];
//        Array[hole]=x;
//    }
//
//    void percolateDown(int hole)
//    {
//        int child;
//        T tmp=Array[hole];
//        for (;hole*2<=currentsize_;hole=child)
//        {
//            child=hole*2;
//            if (child!=currentsize_ &&Array[child+1]<Array[child])
//                child++;
//            if (Array[child]<tmp) Array[hole]=Array[child];
//            else break;
//        }
//        Array[hole]=tmp;
//    }
//    T  dequeue()
//    {
//        T minItem;
//        minItem=Array[1];
//        Array[1]=Array[currentsize_--];
//        percolateDown(1);
//        return minItem;
//    }
//    ~priorityQueue()
//    {
////        cout<<"2delete array"<<endl;
////        delete [] Array;
//    }
//};
//
//class linkgraph{
//public:
//    int vers;
//    struct edgenode{
//        int end;
//        edgenode * next;
//        int weight;
//        edgenode (int e,int w,edgenode*n=NULL)
//        {
//            end=e;next=n;weight=w;
//        }
//    };
//
//    struct firstnode{
//        int ver;
//        edgenode *head;
//        int edges;
//        firstnode(edgenode *h=NULL)
//        {
//            head=h;edges=0;
//        }
//    };
//
//    firstnode *list;
//
//    linkgraph(int vsize_)
//    {
//        list=new firstnode[vsize_+1];
//        vers=vsize_;
//        for (int i=1;i<vsize_+1;++i)
//        {
//            list[i].ver=i;
//        }
//    }
//
//    void insert(int a,int b,int w)
//    {
//        list[a].head=new edgenode(b,w,list[a].head);
//        list[a].edges++;
//    }
//
//};
//
//struct edge
//{
//    int begin,end;
//    int w;
//    bool operator<(const edge &rp)const
//    {return w<rp.w;}
//};
//void kruskal(linkgraph &graph)
//{
//    int ans=0;
//    int edgeAccepted=0,u,v;
//    linkgraph::edgenode *p;
//    edge e;
//    DisjoinSet ds(graph.vers);
//
//    {priorityQueue<edge> pq;
//
//        for (int i=1;i<graph.vers+1;++i)
//        {
//            for (p=graph.list[i].head;p!=NULL;p=p->next)
//
//                if (i<p->end)
//                {
//                    e.begin=i;
//                    e.end=p->end;
//                    e.w=p->weight;
//                    pq.enqueue(e);
//
//                }
//
//        }
//
//        while (edgeAccepted<graph.vers-1)
//        {
//            e=pq.dequeue();
//
//            u=ds.find(e.begin);
//            v=ds.find(e.end);
//            if (u!=v){
//                edgeAccepted++;
//                ds.Union(u,v);
//                //         cout<<graph.list[e.begin].ver<<','<<graph.list[e.end].ver<<' ';
//                ans+=e.w;
//            }
//        }
//        cout<<ans<<endl;}
//}
//
//int main() {
//    int n,m,a,b,w;
//    cin>>n>>m;
//    linkgraph graph1(n);
//    for (int i=0;i<m;++i)
//    {
//        cin>>a>>b>>w;
//        graph1.insert(a,b,w);
//        graph1.insert(b,a,w);
//
//    }
//    kruskal(graph1);
//    //cout << "Program end." << endl;
//    return 0;
//}

//#include <iostream>
//#include <queue>
//using namespace std;
#include <iostream>
using namespace std;
class DisjoinSet{
private:
    int size_;
    int *parent;
public:
    DisjoinSet(int s)
    {
        size_=s;
        parent=new int [size_];
        for (int i=0;i<size_;++i)
            parent[i]=-1;
    }

    ~DisjoinSet()
    {
//        cout<<"1delete set";
        delete [] parent;

    }

    void Union(int root1,int root2)
    {
        if (root1==root2) return;
        if (parent[root1]>parent[root2])
        {
            parent[root2]+=parent[root1];
            parent[root1]=root2;
        }
        else
        {
            parent[root1]+=parent[root2];
            parent[root2]=root1;
        }
    }

    int find(int x)
    {
        if (parent[x]<0)
            return x;
        do{
            x=parent[x];}
        while (parent[x]>=0);
        return x;
    }
};


template <class T>
class priorityQueue{
    int currentsize_;
    T *Array;

public:
    priorityQueue(int c=2000000)
    {
        Array=new T [c];
        currentsize_=0;
    }
    bool isEmpty() const
    {
        return currentsize_==0;
    }
    void enqueue(const T & x)
    {
        int hole=++currentsize_;
        for (;hole>1&&x<Array[hole/2];hole/=2)
            Array[hole]=Array[hole/2];
        Array[hole]=x;
    }

    void percolateDown(int hole)
    {
        int child;
        T tmp=Array[hole];
        for (;hole*2<=currentsize_;hole=child)
        {
            child=hole*2;
            if (child!=currentsize_ &&Array[child+1]<Array[child])
                child++;
            if (Array[child]<tmp) Array[hole]=Array[child];
            else break;
        }
        Array[hole]=tmp;
    }
    T  dequeue()
    {
        T minItem;
        minItem=Array[1];
        Array[1]=Array[currentsize_--];
        percolateDown(1);
        return minItem;
    }
    ~priorityQueue()
    {
//        cout<<"2delete array"<<endl;
        delete [] Array;
    }
};

class linkgraph{
public:
    int vers;
    struct edgenode{
        int end;
        edgenode * next;
        int weight;
        edgenode (int e,int w,edgenode*n=NULL)
        {
            end=e;next=n;weight=w;
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

    linkgraph(int vsize_)
    {
        list=new firstnode[vsize_+1];
        vers=vsize_;
        for (int i=1;i<vsize_+1;++i)
        {
            list[i].ver=i;
        }
    }

    void insert(int a,int b,int w)
    {
        list[a].head=new edgenode(b,w,list[a].head);
        list[a].edges++;
    }
    struct edge
    {
        int begin,end;
        int w;
        bool operator<(const edge &rp)const
        {return w<rp.w;}
    };
    void kruskal()
    {
        int ans=0;
        int edgeAccepted=0,u,v;
        linkgraph::edgenode *p;
        edge e;
        DisjoinSet ds(vers);

        {priorityQueue<edge> pq;

            for (int i=1;i<vers+1;++i)
            {
                for (p=list[i].head;p!=NULL;p=p->next)

                    if (i<p->end)
                    {
                        e.begin=i;
                        e.end=p->end;
                        e.w=p->weight;
                        pq.enqueue(e);

                    }

            }

            while (edgeAccepted<vers-1)
            {
                e=pq.dequeue();

                u=ds.find(e.begin);
                v=ds.find(e.end);
                if (u!=v){
                    edgeAccepted++;
                    ds.Union(u,v);
                    //         cout<<graph.list[e.begin].ver<<','<<graph.list[e.end].ver<<' ';
                    ans+=e.w;
                }
            }
            cout<<ans<<endl;}
    }
};




int main() {
    int n,m,a,b,w;
    cin>>n>>m;
    linkgraph graph1(n);
    for (int i=0;i<m;++i)
    {
        cin>>a>>b>>w;
        graph1.insert(a,b,w);
        graph1.insert(b,a,w);

    }
    graph1.kruskal();
    //cout << "Program end." << endl;
    return 0;
}


