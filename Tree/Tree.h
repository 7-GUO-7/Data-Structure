//
// Created by GUO on 2018/11/26.
//

#ifndef TREE_TREE_H
#define TREE_TREE_H

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










template <class T>
class BinaryTree
{
public:
    struct node
    {
        node *left,*right;
        T data;
        node():left(NULL),right(NULL){};
        node (T item, node *L=NULL, node *R=NULL):data(item),left(L),right(R){}
        ~node(){}
    };

    node *root;


    BinaryTree():root(NULL){}
    BinaryTree(T x){root = new node(x);}
    ~BinaryTree()
    {
        clear(root);
    }

    void clear()
    {
        clear(root);
    }

    bool isEmpty() const
    {
        return root==NULL;
    }

    T Root(T flag) const
    {
        if (root==NULL) return flag;
        else
            return root->data;
    }

//    T lchild(T x, T flag) const;
//    T rchild(T x, T flag) const;
//    void delLeft(T x) const;
//    void delRight(T x) const;
    void preOrder() const
    {
//        preOrder(root); //recursion algorithm

        link_stack<node *>s;
        node* current;
        s.push(root);
        while (!s.isEmpty())
        {
            current=s.pop();
            cout<<current->data<<' ';
            if (current->right!=NULL) s.push(current->right);
            if (current->left!=NULL) s.push(current->left);
        }
    }
    void midOrder() const
    {
//        midOrder(root);
        struct StNode
        {
            node * node1;
            int times;
            StNode (node *n=NULL):node1(n),times(0){}
        };
        link_stack<StNode> s;
        StNode current(root);
        s.push(current);
        while (!s.isEmpty())
        {
            current=s.pop();
            if (++current.times==2)
            {
                cout<<current.node1->data<<' ';
                if (current.node1->right!=NULL)
                    s.push(StNode(current.node1->right));
            }
            else
            {
                s.push(current);
                if (current.node1->left!=NULL)
                {
                    s.push(StNode(current.node1->left));
                }
            }
        }
    }

    void postOrder() const
    {
//        postOrder(root);
        struct StNode
        {
            node * node1;
            int times;
            StNode (node *n=NULL):node1(n),times(0){}
        };
        link_stack<StNode> s;
        StNode current(root);
        s.push(current);
        while(!s.isEmpty())
        {
            current=s.pop();
            if (++current.times==3)
            {
                cout<<current.node1->data<<' ';
                continue;
            }
            s.push(current);
            if (current.times==1) {
                if (current.node1->left != NULL)
                    s.push(StNode(current.node1->left));
            }
            else
            {
                if (current.node1->right!=NULL)
                    s.push(StNode(current.node1->right));
            }
        }
    }

    void levelOrder() const
    {
        link_queue<node*> que;
        node *tmp;
        que.enQueue(root);
        while (!que.isEmpty())
        {
            tmp=que.deQueue();
            cout<<tmp->data<<' ';
            if (tmp->left) que.enQueue(tmp->left);
            if (tmp->right) que.enQueue(tmp->right);
        }
    }

    void createTree (T flag)
    {
        link_queue<node*> que;
        node *tmp;
        T x,ldata,rdata;
        cout<<"please enter the root: ";
        cin>>x;
        root=new node(x);
        que.enQueue(root);

        while (!que.isEmpty())
        {
            tmp=que.deQueue();
            cout<<"input "<< tmp->data<<"'s two sons "<<endl;
            cout<<flag<<" for empty"<<endl;
            cin>>ldata>>rdata;
            if (ldata!=flag) que.enQueue(tmp->left=new node(ldata));
            if (rdata!=flag) que.enQueue(tmp->right=new node(rdata));
        }
        cout<<"complete"<<endl;
    }
//    T parent (T x, T flag) const
//    {
//        return flag;
//    }

    node *find(T x, node *t) const
    {
        node *tmp;
        if (t==NULL) return NULL;
        if (t->data==x) return t;
        if (tmp=find(x,t->left)) return tmp;
        else
            return find(x,t->right);

    }
    void clear(node * &t)
    {
        if (t==NULL)  return;
        clear(t->left);
        clear(t->right);
        delete t;
        t=NULL;
    }

    void preOrder(node *t) const
    {
        if (t==NULL) return;
        cout<<t->data<<' ';
        preOrder(t->left);
        preOrder(t->right);
    }

    void midOrder(node *t) const
    {
        if (t==NULL) return;
        midOrder(t->left);
        cout<<t->data<<' ';
        midOrder(t->right);
    }

    void postOrder(node *t) const
    {
        if (t==NULL) return;
        postOrder(t->left);
        postOrder(t->right);
        cout<<t->data<<' ';
    }

};





#endif //TREE_TREE_H
