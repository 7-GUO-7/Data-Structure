#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class DisjoinSet{
public:
    int size;
    int *parent;

    DisjoinSet(int s)
    {
        size=s;
        parent=new int [size];
        for (int i=0;i<size;++i)
            parent[i]=-1;
    }

    ~DisjoinSet()
    {
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
        if (parent[x]<0) return x;
        return parent[x]=find(parent[x]);
    }
//    int find(int x)
//    {
//        if (parent[x]<0)
//            return x;
//        do{
//            x=parent[x];}
//        while (parent[x]>=0);
//        return x;
//    }
};

//void createPuzzle(int size)
//{
//    int num1,num2;
//    DisjoinSet ds(size*size);
//    srand(time(0));
//
//    while (ds.find((0))!=ds.find(size*size-1))
//    {
//        while(true)
//        {
//            num1=rand()*size*size/(RAND_MAX+1);
//            num2=num1-size;
//        }
//    }
//}



int main() {
    DisjoinSet set1(10);
    set1.Union(1,0);
    cout<<set1.find(0)<<' '<<set1.find(1)<<endl;
    return 0;
}