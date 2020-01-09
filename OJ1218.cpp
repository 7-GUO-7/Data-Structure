#include <iostream>
using namespace std;
class Myset
{
    int *set_for_search;
    int current_num;
public:
    Myset()
    {
        set_for_search=new int[1000];
        current_num=0;
    }

    void insert(int x)
    {
        int flag=0;
        for (int i=0;i<current_num;++i)
            if (set_for_search[i]==x) {
                flag = 1;break;
            }

        if (!flag)
            {
            set_for_search[current_num]=x;
            current_num++;
            }
    }

    void del(int x)
    {
        for (int i=0;i<current_num;++i)
            if (set_for_search[i]==x) {
                for (int j=i;j<current_num-1;++j)
                {
                    set_for_search[j]=set_for_search[j+1];

                }
                current_num--;
                break;
            }
    }



    void intersection(int *x, int len_x)
    {
        int *old=new int[1000];
        int old_num=current_num;
        for (int i=0;i<1000;++i)
        {
            old[i]=set_for_search[i];
        }
        current_num=0;
        for (int i=0;i<old_num;++i) {
            for (int j=0;j<len_x;++j) {
                if (old[i] == x[j] ) {
                    set_for_search[current_num] = x[j];
                    current_num++;
                }
            }
        }
    }

    void show()
    {
        int tmp;
        for (int k1=0;k1<current_num-1;++k1)
        {
            for (int k2=k1;k2<current_num;++k2)
            {
                if (set_for_search[k1]>set_for_search[k2])
                {
                    tmp=set_for_search[k1];
                    set_for_search[k1]=set_for_search[k2];
                    set_for_search[k2]=tmp;
                }
            }
        }

        if (current_num!=0)
        {for (int i=0;i<current_num;++i)
            cout<<set_for_search[i]<<' ';
        cout<<endl;}
        else
            cout<<endl;
    }

};

int main() {
    Myset set1;
    int n,m1,input;
    int input_array[1000];
    char command;
    cin>>n;
    for (int i=0;i<n;++i)
    {
        cin>>command;
        switch(command) {
            case '+': {
                cin >> m1;
                for (int j = 0; j < m1; ++j) {
                    cin >> input;
                    set1.insert(input);
                }
                set1.show();
                break;
            }

            case '-':{
                cin >> m1;
                for (int j = 0; j < m1; ++j) {
                    cin >> input;
                    set1.del(input);
                }
                set1.show();
                break;
            }

            case '*':{
                cin >> m1;
                for (int j = 0; j < m1; ++j) {
                    cin >> input_array[j];
                }
                set1.intersection(input_array,m1);
                set1.show();
                break;

            }


        }
    }


    return 0;
}
