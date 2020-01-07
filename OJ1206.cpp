#include <iostream>
#include <cstring>
using namespace std;
bool flag=1, num=0;
class easy_stack
{
private:
    int *data;
    int current_len;
public:
    easy_stack(){data=new int[1000];current_len=0;}
    bool push(int t){data[current_len]=t;current_len++;}
    int pop() {current_len--;return data[current_len];}
    bool isempty() {return current_len==0;}
};
void error(){}
int main() {
    char tmp[200];
    int judge;
    //bool flag=1;
    easy_stack begin_end,if_else,if_then;
    while(cin>>tmp)
    {
        if (strcmp(tmp,"begin")==0)
        {if (num){error();flag=0;}
            begin_end.push(1);}
        if (strcmp(tmp,"end")==0)
        {
            if (num){error();flag=0;}
            if (begin_end.isempty())
            {error();flag=0;}
            else
                begin_end.pop();
        }

        if (strcmp(tmp,"if")==0)
        {
            if (num){error();flag=0;}
            if_else.push(1);if_then.push(1);num=1;}
        if (strcmp(tmp,"then")==0)
        {
            if (num){num=0;}
            if (if_then.isempty())
            {error();flag=0;}
            else
            {
                if_then.pop();
            }
        }
        if (strcmp(tmp,"else")==0)
        {
            if (num){error();flag=0;}
            if (if_else.isempty())
            {error();flag=0;}
            else
            {
                if_else.pop();
            }
        }
    }
    if (!(if_then.isempty())||! (begin_end.isempty()))
    {error();flag=0;}

    if (flag)
        cout<<"Match!"<<endl;
    else
        cout<<"Error!"<<endl;
    return 0;
}
