#include <iostream>
#include <cstdlib>
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
        if (parent[x]<0)
            return x;
        do{
            x=parent[x];}
        while (parent[x]>=0);
        return x;
    }
};
int record[10000000];
int record_count=0;
int entrance;
int **wall;
bool search(int record[],int record_count,int x)
{
    for (int i=0;i<record_count;++i)
    {
        if (record[i]==x)
            return 1;
    }
    return 0;
}


void dfs(int x,int final,int *level_list,DisjoinSet & set,int **wall)
{
    int left,right;
    while (true)
    {
        if (x==final){
            for (int i=0;i<record_count;++i) {
                cout << record[i] << ' ';

            }
            cout<<endl;
            exit(0);
        }
        else
        {
            if (x==1)
            {
                if (wall[x][x+level_list[x]]&&!search(record,record_count,x+level_list[x]))
                {
                    record[record_count++]=x+level_list[x];
                    dfs(x+level_list[x],final,level_list,set,wall);

                }
                if (wall[x][x+level_list[x]+1]&&!search(record,record_count,x+level_list[x]+1))
                {
                    record[record_count++]=x+level_list[x]+1;
                    dfs(x+level_list[x]+1,final,level_list,set,wall);

                }
                record_count--;break;
            }
            else{
                left=(level_list[x-1]+1)*level_list[x-1]/2+1;
                right=(level_list[x]+1)*level_list[x]/2;

                if (wall[x][x-level_list[x]]&& x!=left && !search(record,record_count,x-level_list[x]))
                {
                    record[record_count++]=x-level_list[x];

                    dfs(x-level_list[x],final,level_list,set,wall);

                }
                if (wall[x][x-level_list[x]+1]&&x!=right && !search(record,record_count,x-level_list[x]+1))
                {
                    record[record_count++]=x-level_list[x]+1;
                    dfs(x-level_list[x]+1,final,level_list,set,wall);

                }
                if (wall[x][x+level_list[x]]&&!search(record,record_count,x+level_list[x]))
                {
                    record[record_count++]=x+level_list[x];
                    dfs(x+level_list[x],final,level_list,set,wall);

                }
                if (wall[x][x+level_list[x]+1]&& !search(record,record_count,x+level_list[x]+1))
                {
                    record[record_count++]=x+level_list[x]+1;
                    dfs(x+level_list[x]+1,final,level_list,set,wall);

                }
                record_count--;break;
            }
        }
    }
}

int main() {
    int n,exit,position,command,left,right;
    cin>>n>>entrance>>exit;
    int num=((1+n)*n)/2;
    int *level_list=new int[num+1];
    int **wall=new int *[num+1];
    for (int i =0;i<num+1;++i)
    {
        wall[i]=new int [num+1];
    }

    for (int i =0;i<num+1;++i)
    {
        for (int j=0;j<num+1;++j)
        {
            wall[i][j]=0;
        }
    }

    int level=1;
    int level_sum=1;
    for (int i=1;i<num+1;++i)
    {
        if (i>level_sum)
        {
            level++;
            level_sum+=level;
        }
        level_list[i]=level;


    }

    DisjoinSet set(num+1);
    while (cin>>position)
    {
        cin>>command;
        switch (command)
        {
            case 0:
            {
                if (position==1)break;
                left=(level_list[position-1]+1)*level_list[position-1]/2+1;
                if (position!=left && (set.find(position)!=set.find(position-level_list[position]))) {
                    {set.Union(set.find(position), set.find(position - level_list[position]));
                        wall[position][position - level_list[position]]=1;
                        wall[position - level_list[position]][position]=1;

                    }
                }
                break;
            }
            case 1:
            {
                if (position==1)break;
                right=(level_list[position]+1)*level_list[position]/2;
                if (position!=right && (set.find(position)!=set.find(position-level_list[position]+1))) {
                    set.Union(set.find(position), set.find(position - level_list[position] + 1));
                    wall[position][position - level_list[position]+1]=1;
                    wall[position - level_list[position]+1][position]=1;

                }
                break;
            }
            case 2:
            {
                if (set.find(position)!=set.find(position+level_list[position]))
                {
                    set.Union(set.find(position),set.find(position+level_list[position]));
                    wall[position][position + level_list[position]]=1;
                    wall[position + level_list[position]][position]=1;

                }
                break;
            }
            case 3:
            {
                if (set.find(position)!=set.find(position+level_list[position]+1))
                {
                    set.Union(set.find(position),set.find(position+level_list[position]+1));
                    wall[position][position + level_list[position]+1]=1;
                    wall[position + level_list[position]+1][position]=1;
                }
                break;}
        }
        if (set.find(entrance)==set.find(exit))
            break;


    }
    record[record_count++]=entrance;
    dfs(entrance,exit,level_list,set,wall);




    return 0;
}
