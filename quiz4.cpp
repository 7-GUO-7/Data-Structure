#include <iostream>
using namespace std;
class openHashTable{
private:
    struct node {
        int  data;
        node  *next;
        node (int d, node *n = NULL)
        { data = d;  next = n; }
        node () {next = NULL;}
    };
    node **array;
    int  size;
    int (*key)( int x);
    static int defaultKey(int x) { return (x+2000000)%270000; }
public:
    openHashTable(int length = 101, int (*f)( int x) = defaultKey){
        size = length;
        array = new node*[size];
        key = f;
        for (int i = 0; i < size; ++i) array[i] = NULL;

    }
//    ~openHashTable() ;

    int find( int x) const{
        int pos ;
        int count=0;
        node *p;
        pos = key(x) % size;
        p = array[pos];
        while (p!=NULL)
        {
            if (p->data==x) count++;
            p=p->next;
        }
        return count;
//        while (p != NULL && !(p->data == x) ) p = p->next;
//        if (p == NULL) {//cout<<"N"<<endl;
//             return 0;}
//        else {//cout<<"Y"<<endl;
//             return 1;}

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
        if (array[pos]->data == x) {
            array[pos] = p->next;    delete p;    return;	   }
        while (p->next != NULL && !(p->next->data == x) ) p = p->next;
        if (p->next != NULL) {
            q = p->next;   p->next = q->next;   delete q;    }

    }
};






int a[1000]={0};
int b[1000]={0};
int c[1000]={0};
int d[1000]={0};
int main() {
    openHashTable hash_table(270000);
    int n;
    int count=0;
    cin>>n;
    for (int i=0;i<n;++i)
    {
        cin>>a[count]>>b[count]>>c[count]>>d[count];
        count++;
    }
    for (int j1=0;j1<count;++j1) {
        for (int j2 = 0; j2 < count; ++j2) {
            hash_table.insert(a[j1] + b[j2]);
        }
    }
    int all_sum=0;
    int tmp_times=0;
    int sum;
    for (int j1=0;j1<count;++j1)
    {
        for (int j2 = 0; j2 < count; ++j2)
        {
            tmp_times=0;
            sum=-(c[j1] + d[j2]);
            all_sum+=hash_table.find(sum);
//            while (hash_table.find(sum))
//            {
//                tmp_times++;
//                hash_table.remove(sum);
//            }
//            for (int k=0;k<tmp_times;++k)
//            {
//                hash_table.insert(sum);
//            }

            all_sum+=tmp_times;
        }
    }
    cout<<all_sum;
    return 0;
}