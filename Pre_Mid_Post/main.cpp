#include <iostream>
#include <cstring>
using namespace std;
template <class elemType>
class Queue{
public:
    virtual bool isEmpty() const=0;
    virtual void enQueue(const elemType &x)=0;
    virtual elemType deQueue()=0;
    virtual elemType getHead()const=0;
    virtual ~Queue(){}
};

template <class elemType>
class link_queue:public Queue<elemType>
{
private:
    struct node{
        elemType data;
        node *next;
        node(const elemType &x, node *N= NULL)
        {data=x;next=N;}
        node():next(NULL){}
        ~node(){}
    };

    node *front,*rear;
public:
    link_queue();
    ~link_queue();
    bool isEmpty() const;
    void enQueue(const elemType &x);
    elemType deQueue();
    elemType getHead()const;
};


template <class elemType>
link_queue<elemType>::link_queue() {
    front=rear=NULL;
}

template <class elemType>
link_queue<elemType>::~link_queue() {
    node *tmp;
    while (front!=NULL){
        tmp=front;
        front=front->next;
        delete tmp;
    };
}

template <class elemType>
bool link_queue<elemType>::isEmpty() const {
    return front==NULL;
}


template <class elemType>
elemType link_queue<elemType>::getHead() const {
    return front->data;
}

template <class elemType>
void link_queue<elemType>::enQueue(const elemType &x) {
    if (rear==NULL)
        front=rear=new node(x);
    else
        rear=rear->next=new node(x);
}

template <class elemType>
elemType link_queue<elemType>::deQueue() {
    node *tmp=front;
    elemType value=front->data;
    front=front->next;
    if (front==NULL) rear=NULL;
    delete tmp;
    return value;
}



class node;
void level_print(node* root);
//node* creat_tree_from_pre_and_mid(char *pre, char *mid, int low1, int high1, int low2, int high2);
class node{
public:
    node *left;
    node *right;
    char data;
    node(node *t)
    {left=(t->left);right=(t->right);data=t->data;
    }
    node(char data1='1')
    {left=NULL;right=NULL;data=data1;}

};


node* creat(node *root, char *s, char *s1, int len)
{
    if(len<=0)
        return NULL;
    root=new node;
    root->data=s[0];

    int p=strchr(s1, s[0] )-s1;//len of left-child

    root->left=creat( root->left, s+1, s1, p );
    root->right=creat( root->left, s+p+1, s1+p+1, len-p-1 );

    return root;
}


void link_to_array(node* node,char * array,int i)
{
    if (i>1000) return;
    if (node==NULL)
    {array[i]='1';array[2*i]='1';array[2*i+1]='1';
        link_to_array(NULL,array, 2*i);
        link_to_array(NULL,array, 2*i+1);}

    else
    {array[i]=node->data;
        if (node->left!=NULL)
            array[2*i]=node->left->data;
        else array[2*i]='1';
        if (node->right!=NULL)
            array[2*i+1]=node->right->data;
        else array[2*i+1]='1';
        link_to_array(node->left,array, 2*i);
        link_to_array(node->right,array, 2*i+1);}
}



char array_from_link[1000];

//int count=0;
//void level_print(node* root) {
//
//    link_queue<node *> myqueue;
//    myqueue.enQueue(root);
//    while (!myqueue.isEmpty()) {
//        node *tmp = myqueue.getHead();
//
//        if (tmp->left != NULL)
//            myqueue.enQueue(tmp->left);
//
//        if (tmp->right != NULL)
//            myqueue.enQueue(tmp->right);
//
//        array_from_link[count]=tmp->data;
//        count++;
//        myqueue.deQueue();
//    }
//    int j;
//    for(j=count-1;j>=0;--j)
//    {
//        if (array_from_link[j]!='1')
//            break;
//    }
//    for(int k=0;k<=j;++k){
//        if(array_from_link[k]!='1')
//            cout<<array_from_link[k]<<' ';
//        else cout<<"NULL"<<' ';}}

int main() {
    char pre[10000],mid[10000];
    cin>>pre;
    cin>>mid;

    int len=0;
    while (pre[len]!='\0')
        len++;
    node *root;

    root = new node(creat(root, pre, mid,len));
    char *array=new char[10000];
    link_to_array(root,array,1);

    int j;
    for (j=1000;j>0;j--)
        if (array[j]!='1')
            break;
    for (int k=1;k<=j;++k)
    {
        if (array[k]!='1')
            cout<<array[k]<<' ';
        else
            cout<<"NULL"<<' ';
    }

    return 0;
}
