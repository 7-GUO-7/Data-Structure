#include <iostream>
using namespace std;
int set[10000];
class MYlist{
public:
    int count;
    int *num;
    MYlist()
    {
        count=0;num=new int [10000];
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
};
int main() {
    int n,out1,out2,son1,son2;
    cin>>n;
    cin>>out1>>out2;
    for (int i=1;i<n+1;++i)
    {
        set[i]=-1;
    }

    for (int i=1;i<n+1;++i)
    {
        cin>>son1>>son2;
        set[son1]=i;
        set[son2]=i;
    }

    int ans1,ans2;
    ans1=out1;
    ans2=out2;

    MYlist list1,list2;
    while (ans1!=-1)
    {
        list1.append(ans1);
        ans1=set[ans1];
    }
    while (!list1.find(ans2))
    {
        ans2=set[ans2];
    }
    cout<<ans2;


    return 0;
}