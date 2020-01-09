//
// Created by GUO on 2018/10/19.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H
using namespace std;

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
class array_stack:public Stack<elemType>
{
private:
elemType *elem;
int top_p;
int maxSize;
void doubleSpace();

public:
    array_stack(int initSize=10);
    ~array_stack();
    bool isEmpty() const;
    void push(const elemType &x);
    elemType pop();
    elemType top() const;
};

template <class elemType>
array_stack<elemType>::array_stack(int initSize) {
    elem=new elemType[initSize];
    maxSize=initSize;
    top_p=-1;
}

template <class elemType>
array_stack<elemType>::~array_stack() {
    delete[] elem;
}

template <class elemType>
bool array_stack<elemType>::isEmpty() const {
    return top_p==-1;
}

template <class elemType>
void array_stack<elemType>::push(const elemType &x) {
    if (top_p==maxSize-1) doubleSpace();
    elem[++top_p]=x;
}

template <class elemType>
elemType array_stack<elemType>::pop() {
    return elem[top_p--];
}

template <class elemType>
elemType array_stack<elemType>::top() const {
    return elem[top_p];
}

template <class elemType>
void array_stack<elemType>::doubleSpace() {
    elemType *tmp=elem;
    elem=new elemType[2*maxSize];
    for (int i=0;i<maxSize;++i)
        elem[i]=tmp[i];
    maxSize*=2;
    delete[] tmp;

}




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




#endif //STACK_STACK_H
