#include <iostream>
#include <cstring>
using namespace std;

bool insert(char *a1, char *a2, int n)
{
    if (n>strlen(a1)+1||n<=0)
    {cout<<"Error!"<<endl;
        return 0;}
    else
    {
        char tmp[2000];
        strncpy(tmp,a1,n-1);
        int i=0;
        for (i=0;i<strlen(a2);++i)
        {
            tmp[n-1+i]=a2[i];
        }
        for (i=0;i<strlen(a1)-n+2;++i)
        {
            tmp[n-1+strlen(a2)+i]=a1[n-1+i];
        }
        tmp[strlen(a1)+strlen(a2)]='\0';
        strcpy(a1,tmp);
        return 1;
    }
}

bool del (char *a1, int p, int n)
{
    if (n+p>strlen(a1)+1||n<0||p<=0)
    {cout<<"Error!"<<endl;
    return 0;}
    else {
        char tmp[2000];
        for (int i = 0;i<p-1;++i)
            tmp[i]=a1[i];
        for (int j = p-1;j<strlen(a1)-n;++j)
            tmp[j]=a1[j+n];
        tmp[strlen(a1)-n]='\0';
        strcpy(a1,tmp);
        return 1;
    }
}

int main() {
    char *key[500]; // most 200 lines
    bool change_record[500]={0};
    // this is the record of whether this data was changed.
    // if it was changed, then its record is 1, else 0.
    char command[100];
    int num=0;
    char trash;
    key[0]=new char[2000];
    cin.getline(key[0],2000,'\n');
    while (key[num][0]!='*')
    {
        num++;
        key[num]=new char[2000];
        cin.getline(key[num],2000,'\n');
        // here must use "getline", because get will leave '\n' in the input stream
        // and you will always get empty because there is always a '\n'.
    }
//    for (int j=0;j<num;++j)
//        cout<<key[j]<<endl;
    cin>>command;
    int n1=0,n2=0,i=0,n3=0;
    char input[2000];
    while (strcmp(command,"quit")!=0)
    {
        if (strcmp(command,"list")==0)
        {
            cin>>n1>>n2;
            if (n1<=0||n1>num||n2>num||n2<n1)
                cout<<"Error!"<<endl;
            else {
                for (i = n1; i <= n2; ++i)
                    cout << key[i - 1] << endl;
            }
        cin>>command;
            continue;
        }

        if (strcmp(command,"ins")==0)
        {
            cin>>n1>>n2;
            cin.get(trash); // get rid of the ' ' before getline.
            cin.getline(input,2000,'\n');
            if (n1>num||n1<=0)
                cout<<"Error!"<<endl;
            else
            {   bool a =
                insert(key[n1-1],input,n2);
                if (a)
                    change_record[n1-1]=1;
            }
        cin>>command;
            continue;
        }

        if (strcmp(command,"del")==0)
        {
            cin>>n1>>n2;
            cin>>n3;
            if (n1>=1&&n1<=num)
            {
                bool b=del(key[n1-1],n2,n3);
                if (b);
                change_record[n1-1]=1;
            }
            else
                cout<<"Error!"<<endl;
            cin>>command;continue;
        }
    }
    for (int i1=0;i1<num;++i1)
    {
        cout<<key[i1]<<endl;
//        if (change_record[i1])
//            cout<<key[i1]<<endl;
    }
    return 0;
}