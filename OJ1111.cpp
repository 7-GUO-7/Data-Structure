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
class array_queue:public Queue<elemType>
{
private:
    elemType *elem;
    int maxSize;
    int front,rear;
    void doubleSpace();

public:
    array_queue(int size=10);
    ~array_queue();
    bool isEmpty() const;
    void enQueue(const elemType &x);
    elemType deQueue();
    elemType getHead()const;
};






template <class elemType>
bool array_queue<elemType>::isEmpty() const {
    return front==rear;
}




template <class elemType>
array_queue<elemType>::array_queue(int size) {
    elem=new elemType[size];
    maxSize=size;
    front=rear=0;
}

template <class elemType>
array_queue<elemType>::~array_queue() {
    delete [] elem;
}

template <class elemType>
elemType array_queue<elemType>::deQueue() {
    front=(front+1)%maxSize;
    return elem[front];
}

template <class elemType>
elemType array_queue<elemType>::getHead() const {
    return elem[(front+1)%maxSize];
}

template <class elemType>
void array_queue<elemType>::enQueue(const elemType &x) {
    if ((rear+1)%maxSize==front) doubleSpace();
    rear=(rear+1)%maxSize;
    elem[rear]=x;
}

template <class elemType>
void array_queue<elemType>::doubleSpace() {
    elemType *tmp=elem;
    elem=new elemType[2*maxSize];
    for (int i=1;i<maxSize;++i)
    {
        elem[i]=tmp[(front+i)%maxSize];
        front=0;rear=maxSize;
        maxSize*=2;
        delete tmp;
    }
}






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

//void tree_from_pre_and_mid(char *pre, char *mid, int len);
//
//struct node{
//    node *left;
//    node *right;
//    char data;
//};
//
//void tree_from_pre_and_mid(char *pre, char *mid, int len,char *data)
//{
//    if (len<=0)
//        return;
//    char tmp=data[]
//    int i=0;
//    for (;i<len;++i)
//    {
//        if (mid[i]==*pre)
//            break;
//    }
//    tree_from_pre_and_mid(pre+1,mid,i);
//    tree_from_pre_and_mid(pre+i+1,mid+i+1,len-(i+1));
//
//}
//
//
//int getLength(int start,int length,int v,char *M);
//void solvePostOrder(int preStart,int inStart,int length,char *L,char *M){
//    if (length<=0)
//        return;
//    int tmp = L[preStart];
//    int len = getLength(inStart,length,tmp,M);//获取左子树的长度len，则右子树的长度为length-len-1
//    solvePostOrder(preStart+1,inStart,len,L,M);//递归解决左子树
//    solvePostOrder(preStart+len+1,inStart+len+1,length-len-1,L,M);//右子树
//    cout<<tmp<<' ';//打印根节点
//
//}
//
//
//int getLength(int start,int length,int v,char *M){//根据中间节点，求左子树的长度
//    for (int i = start,count = 0; count<length; i++,count++){
//        if (M[i] == v)
//            return count;
//    }
//    return 0;
//}
class node;
void level_print(node* root);
node* creat_tree_from_pre_and_mid(char *pre, char *mid, int low1, int high1, int low2, int high2);
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
//    friend node* creat_tree_from_pre_and_mid(char *pre, char *mid, int low1, int high1, int low2, int high2);
//    friend void level_print(node* root);
};




//node* creat_tree_from_pre_and_mid(char *pre, char *mid, int low1, int high1, int low2, int high2)
//{
//    if(low1>high1)
//        return NULL;
//
//    char root=pre[0];
//    node *p=new node(root);
//
//    int count=low2;
//    for (;count<high2;++count)
//    {
//        if (mid[count]==root)
//            break;
//    }
//    p->left=creat_tree_from_pre_and_mid(pre,mid,low1+1,low1+1+count-low2,low2,count-1);
//    p->right=creat_tree_from_pre_and_mid(pre,mid,low1+1+count-low2+1,high1,count+1,high2);
//    return p;
//}

node* creat(node *root, char *s, char *s1, int len)
{
    if(len<=0)
        return NULL;
    root=new node;
    root->data=s[0];

    int p=strchr(s1, s[0] )-s1;

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

int count=0;
void level_print(node* root) {
    node *empty;
    empty=new node;

    bool flag;
    array_queue<node *> myqueue;
    myqueue.enQueue(root);
    while (!myqueue.isEmpty()) {
        node *tmp = myqueue.getHead();

            if (tmp->left != NULL)
                myqueue.enQueue(tmp->left);
//            else
//                myqueue.enQueue(empty);
            if (tmp->right != NULL)
                myqueue.enQueue(tmp->right);
//            else
//                myqueue.enQueue(empty);
//        if (tmp->data!=0)
//        cout<<tmp->data<<' ';
//        else cout<<"NULL"<<' ';
    array_from_link[count]=tmp->data;
    count++;
        myqueue.deQueue();
    }
    int j;
    for(j=count-1;j>=0;--j)
    {
        if (array_from_link[j]!='1')
            break;
    }
    for(int k=0;k<=j;++k){
        if(array_from_link[k]!='1')
        cout<<array_from_link[k]<<' ';
        else cout<<"NULL"<<' ';}
}

int main() {
    char pre[10000],mid[10000];
    cin>>pre;
    cin>>mid;
//    char pre[5]="ABCD",mid[5]="BADC";
    int len=0;
    while (pre[len]!='\0')
        len++;
    node *root;
//    root=new node(creat_tree_from_pre_and_mid(pre,mid,0,3,0,3));
    root = new node(creat(root, pre, mid,len));
    char *array=new char[10000];
    link_to_array(root,array,1);
//    cout<<root->data;
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


//node *tmp=new node;
//node *left=new node;
//node *right=new node;
//tmp->data='a';
//right->data='b';
//left->data='c';
//tmp->left=left;
//tmp->right=right;
//left->left=NULL;
//    left->right=NULL;
//    right->left=NULL;
//    right->right=NULL;
//
//level_print(tmp);
    return 0;
}