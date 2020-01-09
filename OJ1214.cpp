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

template <class elemType>
class Stack{
public:
    virtual bool isEmpty() const=0;
    virtual void push(const elemType &x)=0;
    virtual elemType pop()=0;
    virtual elemType top() const =0;
    virtual ~Stack(){}
};

template <class elemType>
class link_stack:public Stack <elemType> {
private:
    struct node{
        elemType data;
        node *next;
        node(const elemType &x, node *N= NULL)
        {data=x;next=N;}
        node():next(NULL){}
        ~node(){}
    };

    node *top_p;
public:
    link_stack();
    ~link_stack();
    bool isEmpty() const;
    void push(const elemType &x);
    elemType pop();
    elemType top() const;
};


template <class elemType>
link_stack<elemType>::link_stack() {
    top_p=NULL;
}

template <class elemType>
link_stack<elemType>::~link_stack() {
    node *tmp;
    while(top_p!=NULL)
    {
        tmp=top_p;
        top_p=top_p->next;
        delete tmp;
    }
}


template <class elemType>
bool link_stack<elemType>::isEmpty() const {
    return top_p==NULL;
}

template <class elemType>
void link_stack<elemType>::push(const elemType &x) {
    top_p=new node(x,top_p);
}

template <class elemType>
elemType link_stack<elemType>::pop() {
    node *tmp=top_p;
    elemType x=tmp->data;
    top_p=top_p->next;
    delete tmp;
    return x;
}

template <class elemType>
elemType link_stack<elemType>::top() const {
    return top_p->data;
}






class tree_node{
public:

    tree_node *left;
    tree_node *right;
    tree_node *parent;
    int data;
    int times_of_top;
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
        save[i]->times_of_top=0;
    }
    for (int i=1;i<n+1;++i)
    {
        if (array_of_tree[3*i-2]!=0)
        save[i]->left=save[array_of_tree[3*i-2]];
//        else save[i]->left=NULL;
        if (array_of_tree[3*i-1]!=0)
        save[i]->right=save[array_of_tree[3*i-1]];
//        else save[i]->right=NULL;
        save[i]->data=array_of_tree[3*i];
        if (array_of_tree[3*i-2]!=0)
        {save[i]->left->parent=save[i];}
        if (array_of_tree[3*i-1]!=0)
        {save[i]->right->parent=save[i];}
    }
    return save
            ;
}

void taverse(tree_node *save[],int n) {
    tree_node *tmp = save[1];
    tree_node *root = tmp;
    int height = 0;
    int count = 0;

    while (tmp->parent != NULL) {
        tmp = tmp->parent;
        count++;
    }
    if (count > height) {
        height = count;
        root = tmp;
    }//find the root, use the parent to the end.

    link_stack<tree_node *> stack0;//preOrder of BTree, preOrder of the original tree
    tree_node *current;
    stack0.push(root);
    while (!stack0.isEmpty()) {
        current = stack0.pop();
        cout << current->data << ' ';
        if (current->right != NULL) stack0.push(current->right);
        if (current->left != NULL) stack0.push(current->left);
    }
    cout << endl;


    stack0.push(root);// midOrder of BTree, postOrder of the original tree
    while (!stack0.isEmpty()) {
        current = stack0.pop();
        if (++current->times_of_top == 2) {
            cout << current->data << ' ';
            if (current->right != NULL)
                stack0.push(current->right);

        } else {
            stack0.push(current);
            if (current->left != NULL) {
                stack0.push(current->left);
            }
        }

    }
    cout << endl;

    link_queue<tree_node *> queue0;
    queue0.enQueue(root);
    tree_node *flag1;
    while (!queue0.isEmpty()) {
        current = queue0.deQueue();
        cout << current->data << ' ';
        if (current->left) {
            flag1 = current->left;
            queue0.enQueue(flag1);
            while (flag1->right) {
                flag1 = flag1->right;
                queue0.enQueue(flag1);
            }
        }
    }
}


int main() {

    int num_of_node;
    cin>>num_of_node;
    tree_node* save[num_of_node+1];

    int array_of_tree[3*num_of_node+1];
    for (int i=1;i<3*num_of_node+1;++i)
        cin>>array_of_tree[i];
    tree_node **tree=NULL;
    tree=creat(save, num_of_node, array_of_tree);
    taverse(tree,num_of_node);

    return 0;
}