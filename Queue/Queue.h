//
// Created by GUO on 2018/10/19.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H
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
#endif //QUEUE_QUEUE_H
