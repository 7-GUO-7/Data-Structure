#include <iostream>
using namespace std;
class Myset
{
    int *set_for_search;
    int current_num;
public:
    Myset()
    {
        set_for_search=new int[3000];
        current_num=0;
    }

    void insert(int x)
    {
        set_for_search[current_num]=x;
        current_num++;
    }
    void search(int x)
    {
        int flag=0;
        for (int i=0;i<current_num;++i)
            if (set_for_search[i]==x)
            {
                flag=1;
                cout<<'Y'<<endl;
                break;
            }
        if (!flag)
            cout<<'N'<<endl;
    }
};


int main() {
    Myset set1;
    int n,m,tmp;
    cin>>n;
    for (int i=0;i<n;++i)
    {
        cin>>tmp;
        set1.insert(tmp);
    }
    cin>>m;
    for (int i=0;i<m;++i)
    {
        cin>>tmp;
        set1.search(tmp);
    }


    return 0;
}