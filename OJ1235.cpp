#include <iostream>
using namespace std;
template <class T>
class priorityQueue{
    int currentsize_;
    T *Array;

public:
    priorityQueue(int c=2100000)
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
        delete [] Array;
    }
};

int noEdge=210000000;
class adjGraph
{
public:
    struct edgeNode
    {
        int end;
        int weight;
        edgeNode *next;

        edgeNode(int e=0, int w=0, edgeNode *n=NULL)
        {
            end = e;
            weight = w;
            next = n;
        }
    };
    struct verNode
    {
        int ver;
        edgeNode *head;
        verNode(edgeNode *h = NULL) {head = h;}
    };

    verNode *verlist;
    int vers,edges;

    adjGraph(int vsize, int d[])
    {
        vers = vsize;
        edges = 0;
        verlist = new verNode[vsize];
        for(int i=0; i<vers; ++i)   verlist[i].ver = d[i];
    }

    ~adjGraph()
    {
        int i;
        edgeNode *p;
        for(i=0; i<vers; i++)
        {
            while((p = verlist[i].head))
            {
                verlist[i].head = p->next;
                delete p;
            }
        }
        delete [] verlist;
    }

    void insert(int x, int y, int w)
    {
        int u = find(x), v = find(y);
        verlist[u].head = new edgeNode(v, w, verlist[u].head);
        ++edges;
    }

    int find(int v) const
    {
        return v-1;
    }

    struct queueNode
    {
        int distance;
        int node;
        bool operator<(const queueNode &node1) const {return distance<node1.distance;}
    };

    void dijkstra(int start, int end)
    {
        int *distance = new int[vers];
        int *prev = new int[vers];
        int *num_of_pre_node = new int[vers];
        bool *known = new bool[vers];
        int start_point, i, end_point = find(end);
        edgeNode *p;
        priorityQueue<queueNode> q1;
        queueNode min,final;

        for(i=0; i<vers; i++)
        {
            known[i] = false;
            distance[i] = noEdge;
            num_of_pre_node[i]= 0;
        }
        start_point = find(start);
        distance[start_point] = 0;
        prev[start_point] = start_point;
        min.distance = 0;
        min.node = start_point;
        q1.enqueue(min);

        while(!q1.isEmpty())
        {
            min = q1.dequeue();
            if(known[min.node]) continue;
            known[min.node] = true;
            for(p = verlist[min.node].head; p != NULL; p = p->next)
            {
                if(!known[p->end] && ((distance[p->end] > min.distance+ p->weight)
                || ((distance[p->end] == min.distance+ p->weight) && (num_of_pre_node[p->end] > num_of_pre_node[min.node]+1))))
                {
                    final.distance = distance[p->end] = min.distance+ p->weight;
                    num_of_pre_node[p->end] = num_of_pre_node[min.node] + 1;
                    prev[p->end] = min.node;
                    final.node = p->end;
                    q1.enqueue(final);
                }
            }
            if(min.node == end_point) break;
        }
        cout<<distance[end_point]<<endl;
        printpath(start_point, end_point, prev);
    }

    void printpath (int start, int end, int prev[])
    {
        if(start == end)
        {
            cout<<verlist[start].ver;
            return;
        }
        printpath(start, prev[end], prev);
        cout<<' '<<verlist[end].ver;
    }

};
int main() {
    int n,m,start,end;
    cin>>n>>m>>start>>end;
    int point_list[n];
    for(int i=0; i<n; i++) point_list[i] = i+1;
    adjGraph graph1(n, point_list);
    for(int i=0; i<m; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        graph1.insert(a, b, c);
    }

    graph1.dijkstra(start, end);

    return 0;
}