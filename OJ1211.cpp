#include <iostream>
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






class tree_node{
public:

    tree_node *left;
    tree_node *right;
    tree_node *parent;
    int data;
};


tree_node ** creat(tree_node *save[],int n,int * array_of_tree)
{

    for (int i=0;i<n+1;++i)
    {
        save[i]=new tree_node;
        save[i]->left=NULL;
        save[i]->right=NULL;
        save[i]->parent=NULL;
        save[i]->data=0;
    }
    for (int i=1;i<n+1;++i)
    {
        save[i]->left=save[array_of_tree[2*i-1]];
        save[i]->right=save[array_of_tree[2*i]];//fill every node with a left child and a right child
        save[i]->data=1;
        if (array_of_tree[2*i-1]!=0)
        {save[i]->left->data=1;save[i]->left->parent=save[i];}
        if (array_of_tree[2*i]!=0)
        {save[i]->right->data=1;
            save[i]->right->parent=save[i];}
    }
    return save
            ;
}

bool full_tree_judge(tree_node *save[],int n)
{
    tree_node *tmp=save[1];
    tree_node *root=tmp;
    int height=0;int count=0;
//    for (int i=1;i<n;++i) {
//        tmp = save[i];
    count = 0;
    while (tmp->parent != NULL) {
        tmp = tmp->parent;
        count++;
    }
    if (count > height) {
        height = count;
        root = tmp;
    }
//    }
    int data_record[200000]={0},j=0;
    link_queue<tree_node*> queue1;
    queue1.enQueue(root);
    tree_node *tmp2;
    while (!queue1.isEmpty())
    {
        tmp2=queue1.deQueue();
        data_record[j]=tmp2->data;
        j++;
        if (tmp2->left) queue1.enQueue(tmp2->left);
        if (tmp2->right) queue1.enQueue(tmp2->right);
    }
    for (int i=0;i<n+1;++i)
    {
        delete save[i];}
    int flag=0;
    for (int t=200000-1;t>=0;--t)
    {
        if (data_record[t]!=0)
            flag=1;
        if (flag&&data_record[t]==0)
            return 0;
    }
    return 1;

}



//int * build(int n,int *array_of_tree)
//{
//    array_of_tree=new int[200000];
//    for (int i=1;i<=n;i+=2)
//    {
//        cin>>array_of_tree[i];
//        cin>>array_of_tree[i+1];
//    }
//    return array_of_tree;
//}

int main() {

    int num_of_node;
    cin>>num_of_node;
    tree_node* save[num_of_node+1];

    int array_of_tree[2*num_of_node+1];
    for (int i=1;i<2*num_of_node+1;++i)
        cin>>array_of_tree[i];
    tree_node **tree=NULL;
    tree=creat(save, num_of_node, array_of_tree);
    if(full_tree_judge(tree,num_of_node))cout<<'Y'<<endl;
    else cout<<'N'<<endl;

    return 0;
}