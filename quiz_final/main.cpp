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
    void find(int x,int *len,int a[])
    {
        int tmp_count=0;
        for (int i=0;i<count;++i)
        {
            if (num[i]==x&&x%2==0)
            {
                a[tmp_count]=num[i+1];
                tmp_count++;
            }
            if (num[i]==x&&x%2==1)
            {
                a[tmp_count]=num[i-1];
                tmp_count++;
            }
        }
        *len=tmp_count;
//        return 0;
    }
    void find_new(int x,int *len,int a[],int b[])
    {
        int tmp_count=0;
        for (int i=0;i<count;++i)
        {
            if (num[i]==x&&x%2==0)
            {
                a[tmp_count]=num[i+1];
                b[tmp_count]=1;
                tmp_count++;
            }
            if (num[i]==x&&x%2==1)
            {
                a[tmp_count]=num[i-1];
                b[tmp_count]=0;
                tmp_count++;
            }
        }
        *len=tmp_count;
//        return 0;
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


int false_count=0;
int main() {
//    int **judge;
//    judge=new int *[1050];
    MYlist list1,list2;
    DisjoinSet set1(3000);
    int N,K;
    cin>>N>>K;
//    for (int i=0;i<1050;++i)
//        judge[i]=new int [1050];
//    for (int i=0;i<1050;++i)
//        for (int j=0;j<1050;++j)
//            judge[i][j]=0;

    int d,x,y;
    for (int i=0;i<K;++i) {
        cin >> d >> x >> y;
        if (x > N || y > N)
            false_count++;
        else {
            if (d == 2 && x == y)
                false_count++;
        }

        {
            if (d == 1) {
                if (set1.find(x) == x && set1.find(y) == y) {
                    set1.Union(1046, x);
                    set1.Union(1046, y);
                    list1.append(x);
                    list1.append(y);
                }
                if (set1.find(x) == x && set1.find(y) != y)
                    set1.Union(y, x);
                if (set1.find(x) != x && set1.find(y) == y)
                    set1.Union(x, y);
                if (set1.find(x) != x && set1.find(y) != y) {
                    if (set1.find(x) != set1.find(y))
                        false_count++;
                    else {}
                }
            }

            if (d == 2) {
                if (set1.find(x) == x && set1.find(y) == y) {
                    list2.append(x);
                    list2.append(y);
//            set1.Union(1048,x);
//            set1.Union(1049,y);
                }
                if (set1.find(x) != x && set1.find(y) == y) {
                    if (set1.find(x) == 1049) {
                        int b[1000];
                        int out_judge[1000];
                        int len_out = 0;
                        list2.find_new(y, &len_out, b, out_judge);
                        for (int k1 = 0; k1 < len_out; ++k1) {
                            if (out_judge[k1]) {
                                if (set1.find(1048) != set1.find(b[k1]))
                                    set1.Union(1048, b[k1]);
                                else
                                    false_count++;
                            } else {
                                if (set1.find(1049) != set1.find(b[k1]))
                                    set1.Union(1049, b[k1]);
                                else
                                    false_count++;
                            }
                        }


                        set1.Union(1047, y);
                        if (set1.find(y) == 1046) {
                            int a[1000];
                            int len = 0;
                            list1.find(y, &len, a);
                            for (int k1 = 0; k1 < len; ++k1) {
                                set1.Union(1047, a[k1]);
                            }
                        }
                    }
                    if (set1.find(x) == 1048) {
                        int b[1000];
                        int out_judge[1000];
                        int len_out = 0;
                        list2.find_new(y, &len_out, b, out_judge);
                        for (int k1 = 0; k1 < len_out; ++k1) {
                            if (out_judge[k1]) {
                                if (set1.find(1047) != set1.find(b[k1]))
                                    set1.Union(1047, b[k1]);
                                else
                                    false_count++;
                            } else {
                                if (set1.find(1048) != set1.find(b[k1]))
                                    set1.Union(1048, b[k1]);
                                else
                                    false_count++;
                            }
                        }


                        set1.Union(1049, y);
                        if (set1.find(y) == 1046) {
                            int a[1000];
                            int len = 0;
                            list1.find(y, &len, a);
                            for (int k1 = 0; k1 < len; ++k1) {
                                set1.Union(1049, a[k1]);
                            }
                        }
                    }
                    if (set1.find(x) == 1047) {
                        int b[1000];
                        int out_judge[1000];
                        int len_out = 0;
                        list2.find_new(y, &len_out, b, out_judge);
                        for (int k1 = 0; k1 < len_out; ++k1) {
                            if (out_judge[k1]) {
                                if (set1.find(1049) != set1.find(b[k1]))
                                    set1.Union(1049, b[k1]);
                                else
                                    false_count++;
                            } else {
                                if (set1.find(1047) != set1.find(b[k1]))
                                    set1.Union(1047, b[k1]);
                                else
                                    false_count++;
                            }
                        }


                        set1.Union(1048, y);
                        if (set1.find(y) == 1046) {
                            int a[1000];
                            int len = 0;
                            list1.find(y, &len, a);
                            for (int k1 = 0; k1 < len; ++k1) {
                                set1.Union(1048, a[k1]);
                            }
                        }
                    }
                }


                if (set1.find(x) == x && set1.find(y) != y) {
                    if (set1.find(y) == 1049) {
                        int b[1000];
                        int out_judge[1000];
                        int len_out = 0;
                        list2.find_new(x, &len_out, b, out_judge);
                        for (int k1 = 0; k1 < len_out; ++k1) {
                            if (out_judge[k1]) {
                                if (set1.find(1048) != set1.find(b[k1]))
                                    set1.Union(1048, b[k1]);
                                else
                                    false_count++;
                            } else {
                                if (set1.find(1049) != set1.find(b[k1]))
                                    set1.Union(1049, b[k1]);
                                else
                                    false_count++;
                            }
                        }

                    }
                    set1.Union(1047, x);
                    if (set1.find(x) == 1046) {
                        int a[1000];
                        int len = 0;
                        list1.find(x, &len, a);
                        for (int k1 = 0; k1 < len; ++k1) {
                            set1.Union(1047, a[k1]);
                        }
                    }

                    if (set1.find(y) == 1048) {
                        int b[1000];
                        int out_judge[1000];
                        int len_out = 0;
                        list2.find_new(x, &len_out, b, out_judge);
                        for (int k1 = 0; k1 < len_out; ++k1) {
                            if (out_judge[k1]) {
                                if (set1.find(1047) != set1.find(b[k1]))
                                    set1.Union(1047, b[k1]);
                                else
                                    false_count++;
                            } else {
                                if (set1.find(1048) != set1.find(b[k1]))
                                    set1.Union(1048, b[k1]);
                                else
                                    false_count++;
                            }
                        }

                    }
                    set1.Union(1049, x);
                    if (set1.find(x) == 1046) {
                        int a[1000];
                        int len = 0;
                        list1.find(x, &len, a);
                        for (int k1 = 0; k1 < len; ++k1) {
                            set1.Union(1049, a[k1]);
                        }
                    }
                    if (set1.find(y) == 1047) {
                        int b[1000];
                        int out_judge[1000];
                        int len_out = 0;
                        list2.find_new(x, &len_out, b, out_judge);
                        for (int k1 = 0; k1 < len_out; ++k1) {
                            if (out_judge[k1]) {
                                if (set1.find(1049) != set1.find(b[k1]))
                                    set1.Union(1049, b[k1]);
                                else
                                    false_count++;
                            } else {
                                if (set1.find(1047) != set1.find(b[k1]))
                                    set1.Union(1047, b[k1]);
                                else
                                    false_count++;
                            }
                        }

                    }
                    set1.Union(1048, x);
                    if (set1.find(x) == 1046) {
                        int a[1000];
                        int len = 0;
                        list1.find(x, &len, a);
                        for (int k1 = 0; k1 < len; ++k1) {
                            set1.Union(1048, a[k1]);
                        }
                    }

                }
                if (set1.find(x) != x && set1.find(y) != y) {
                    if (set1.find(x) == 1049 && set1.find(y) != 1047)
                        false_count++;
                    if (set1.find(x) != 1049)
                        if (set1.find(y) != set1.find(x) + 1)
                            false_count++;
                        else {}
                }


            }
        }

    }
    cout<<false_count;
    return 0;
}