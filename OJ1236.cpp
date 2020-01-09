#include <iostream>
#include <queue>
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


bool find(queue<int> q1,int x)
{
    int a;
    while (!q1.empty())
    {
        a=q1.front();
        q1.pop();
        if (a==x)
            return 1;

    }
    return 0;
}


int distance_data[10000]={0};
int main() {
    for (int i=0;i<10000;++i)
    {distance_data[i]=800;}
    int n,m,start,end,a,b,weight;
    cin>>n>>m>>start>>end;
    MYlist **edge_list=new MYlist* [n+1];
    int *edge_num=new int [n+1];
    for (int i=0;i<n+1;++i)
    {
        edge_list[i]=new MYlist;
        edge_num[i]=0;
    }
        for (int i=0;i<m;++i)
    {
        cin>>a>>b>>weight;
        edge_list[a]->append(b);
        edge_list[a]->append(weight);
        edge_num[a]++;
    }

    queue<int> queue1;
    int v;
    distance_data[start]=0;
    queue1.push(start);
    while (!queue1.empty())
    {
        v=queue1.front();
        queue1.pop();
        for (int i=0;i<edge_num[v];++i)
        {
            if (distance_data[v]+edge_list[v]->num[2*i+1]<distance_data[edge_list[v]->num[2*i]])

            {
                distance_data[edge_list[v]->num[2*i]]=distance_data[v]+edge_list[v]->num[2*i+1];
                if (!find(queue1,edge_list[v]->num[2*i]))
                {
                    queue1.push(edge_list[v]->num[2*i]);
                }
            }
        }
    }
    cout<<distance_data[end]<<endl;
    return 0;
}