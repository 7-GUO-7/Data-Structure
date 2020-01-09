#include <iostream>
using namespace std;

class closeHashTable{
private:
    struct node { //散列表的结点类
        int  data;
        int  state;  //0 -- empty   1 -- active   2 -- deleted
        node() {state = 0;}
    };
    node *array;
    int  size;
    int (*key)(const int &x);
    static int defaultKey(const int &x) {return x%11;}
public:
    closeHashTable(int length = 101, int (*f)(const int &x) = defaultKey)
    {
        size = length;
        array = new node[size];
        key = f;
        for(int i=0;i<length;++i)
            array[i].state=0;
    }

//    ~closeHashTable() {delete [] array;}
    bool find(const int &x) const{
        int initPos, pos ;
        initPos = pos = key(x) % size;
        do {
            if (array[pos].state == 0) {
                cout<<"N"<<endl;
                return 0;
            }     // 没有找到
            if (array[pos].state == 1 && array[pos].data == x)    // 找到
                {cout<<"Y"<<endl;return 1;}
            pos = (pos+1) % size;
        } while (pos != initPos);

    }
    void insert(const int &x){
        int initPos, pos ;

        initPos = pos = key(x) % size;
        do {
            if (array[pos].state != 1) {       // 找到空单元
                array[pos].data = x;
                array[pos].state = 1;
                return;
            }
            pos = (pos+1) % size;
        } while (pos != initPos);

    }
    void remove(const int &x){
        int initPos, pos ;
        initPos = pos = key(x) % size;
        do {
            if (array[pos].state == 0) return;
            if (array[pos].state == 1 && array[pos].data == x) {  // 找到，删除
                array[pos].state = 2;
                return;
            }
            pos = (pos+1) % size;
        } while (pos != initPos);

    }
};

class openHashTable{
private:
    struct node { //开散列表中链表的结点类
        int  data;
        node  *next;
        node (const int &d, node *n = NULL)
        { data = d;  next = n; }
        node () {next = NULL;}
    };
    node **array;//指针数组
    int  size;
    int (*key)(const int &x);
    static int defaultKey(const int &x) { return x; }
public:
    openHashTable(int length = 101, int (*f)(const int &x) = defaultKey){
        size = length;
        array = new node*[size];
        key = f;
        for (int i = 0; i < size; ++i) array[i] = NULL;

    }
//    ~openHashTable() ;

    bool find(const int &x) const{
        int pos ;
        node *p;
        pos = key(x) % size;
        p = array[pos];
        while (p != NULL && !(p->data == x) ) p = p->next;
        if (p == NULL) {cout<<"N"<<endl;return 0;}
        else {cout<<"Y"<<endl;return 1;}

    }
    void insert(const int &x){
        int pos ;
        node *p;
        pos = key(x) % size;
        array[pos] = new node(x, array[pos]);

    }
    void remove(const int &x){
        int  pos ;
        node *p, *q;
        pos = key(x) % size;
        if (array[pos] == NULL) return;
        p = array[pos];
        if (array[pos]->data == x) {                          // 删除第一个节点
            array[pos] = p->next;    delete p;    return;	   }
        while (p->next != NULL && !(p->next->data == x) ) p = p->next;
        if (p->next != NULL) {
            q = p->next;   p->next = q->next;   delete q;    }

    }
};

int main() {
    int a[6]={17,12,23,60,29,38};
    closeHashTable hash(10);
    for (int i =0;i<6;++i){
        hash.insert(a[i]);
    }
    hash.remove(12);
    hash.find(12);
    hash.find(15);
    hash.find(17);

    openHashTable hash2(10);
    for (int i =0;i<6;++i){
        hash2.insert(a[i]);
    }
    hash2.insert(17);

    hash2.find(12);
    hash2.find(15);

    hash2.find(17);
    hash2.remove(17);
    hash2.find(17);
    hash.remove(17);
    hash.find(17);
    return 0;
}