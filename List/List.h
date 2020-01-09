//
// Created by GUO on 2018/10/13.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H
using namespace std;


template <class elemType>
class List
{
public:
    virtual void clear()=0;
    virtual int length() const=0;
    virtual void insert(int i, const elemType &x )=0;
    virtual void remove(int i)=0;
    virtual int search(const elemType &x) const=0;
    virtual elemType visit(int i) const=0;// show element i
    virtual void taverse() const=0;//show all the elements
    virtual ~List(){}
};



template <class elemType>
class array_list: public List<elemType>
{
private:
    elemType *data;
    int current_length;
    int max_size;
    void double_space();

public:
    array_list(int init_size=10);
    ~array_list();
    void clear();//clear all the list
    int length() const; // cout the length of this array_list
    void insert(int i, const elemType &x );// array_list[i]=x;
    void remove(int i); // remove 3 is remove array_list[3]
    int search(const elemType &x) const; //return where x is, array_list[i]=x,return i
    elemType visit(int i) const; //return array_list[i]
    void taverse() const; // cout all the elements
};



template <class elemType>
class link_list:public List<elemType>{
private:
    struct node{
        elemType data;
        node *next;

        node (const elemType &x,node *n=NULL)
        {data=x;next=n;}
        node():next(NULL){} // for the head node
        ~node(){}
    };

    node *head;
    int currentLength;
    node* move(int i) const


    //return the address of node i, move(3) returns the address of link_list[3]


    {
        node *p=head;
        for (int t=0;t<=i;++t)
            p=p->next;
        return p;
    }
public:
    link_list();
    ~link_list(){clear();delete head;}
    void clear();//clear all the list
    int length() const { return currentLength;}// cout the length of this link_list
    void insert(int i, const elemType &x);// link_list[i]=x;
    void remove(int i); // remove 3 is remove link_list[3]
    int search(const elemType &x) const;//return where x is, link_list[i]=x,return i
    elemType visit(int i) const;//return link_list[i]
    void taverse() const;// cout all the elements
};






template <class elemType>
link_list<elemType>::link_list() {
    head=new node;
    currentLength=0;
}

template <class elemType>
void link_list<elemType>::clear() {
    node *p=head->next, *q;
    head->next=NULL;
    while(p!=NULL){
        q=p->next;
        delete p;
        p=q;
    }
    currentLength=0;
}

template <class elemType>
void link_list<elemType>::insert(int i, const elemType &x) {
    node *pos;
    pos=move(i-1);
    pos->next=new node(x,pos->next);
    ++currentLength;
}

template <class elemType>
void link_list<elemType>::remove(int i) {
    node *pos,*delp;
    pos=move(i-1);
    delp=pos->next;
    pos->next=delp->next;
    delete delp;
    --currentLength;
}

template <class elemType>
int link_list<elemType>::search(const elemType &x) const {
    node *p=head->next;
    int i=0;
    while (p!=NULL && p->data !=x){p=p->next;++i;}
    if (p==NULL) return -1;
    else return i;
}

template <class elemType>
elemType link_list<elemType>::visit(int i) const {
    return move(i)->data;
}

template <class elemType>
void link_list<elemType>::taverse() const {
    node *p= head->next;
    cout<<"the list is: "<<endl;
    while (p!=NULL){
        cout<<p->data<<' ',
        p=p->next;
    }
    cout<<endl;
}








template <class elemType>
array_list<elemType>::array_list(int init_size) {
    data=new elemType[init_size];
    max_size=init_size;
    current_length=0;
}

template <class elemType>
array_list<elemType>::~array_list() {
    delete [] data;
}

template <class elemType>
void array_list<elemType>::clear() {
    current_length=0;
}

template <class elemType>
int array_list<elemType>::length() const {
    return current_length;
}

template <class elemType>
elemType array_list<elemType>::visit(int i) const {
    return data[i];
}

template <class elemType>
int array_list<elemType>::search(const elemType &x) const {
    int i;
    for (i=0;i<current_length&&data[i]!=x;++i)
        if (i==current_length) return -1;
    return i;
}

template <class elemType>
void array_list<elemType>::double_space() {
    elemType *tmp=data;
    max_size*=2;
    data=new elemType[max_size];
    for (int i=0;i<current_length;++i)
        data[i]=tmp[i];
    delete [] tmp;
}

template <class elemType>
void array_list<elemType>::insert(int i, const elemType &x) {
    if (current_length==max_size)
        double_space();
    for(int j=current_length;j>i;j--)
        data[j]=data[j-1];
    data[i]=x;
    ++current_length;
}

template <class elemType>
void array_list<elemType>::remove(int i) {
    for (int j=i;j<current_length;j++)
        data[j]=data[j+1];
    --current_length;
}

template <class elemType>
void array_list<elemType>::taverse() const {
    cout<<"The list is: "<<endl;
    for (int i=0;i<current_length;++i)
        cout<<data[i]<<' ';
    cout<<endl;
}


#endif //LIST_LIST_H
