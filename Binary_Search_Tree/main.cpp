#include <iostream>
#include <cstring>
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


class node
{
public:
    node *left;
    node *right;
    int data;
    node(int x=0)
    {
        left=NULL;
        right=NULL;
        data=x;
    }
};

class search_tree
{
public:
    node *root;
    int current_node;
    search_tree()
    {
        root=NULL;
        current_node=0;
    }

    bool find(node *&tree_node,int x)
    {
        if (tree_node==NULL) return 0;
        if (tree_node->data==x) return 1;
        if (tree_node->data>=x)
            return find(tree_node->left,x);
        else
            return find(tree_node->right,x);
    }
    void search(node *&tree_node,int x) // print the find answer
    {
        if (find(tree_node,x))
            cout<<'Y'<<endl;
        else
            cout<<'N'<<endl;
    }

    int find_ith(search_tree *search_tree,int i)
    {
        struct StNode
        {
            node *node1;
            int times;
            StNode (node *N=NULL):node1(N),times(0){}
        };
        if (search_tree->current_node<i || i<=0) {cout<<'N'<<endl;return -1;}//error flag is -1
        int tmp[5100]={0};
        int count=0;
        link_stack<StNode> stack1;
        StNode current(search_tree->root);
        stack1.push(current);
        while (!stack1.isEmpty())
        {
            current=stack1.pop();
            if (++current.times==2)
            {
                tmp[count++]=current.node1->data;
                if (current.node1->right!=NULL)
                    stack1.push(StNode (current.node1->right));
            }
            else
            {
                stack1.push(current);
                if (current.node1->left!=NULL)
                    stack1.push(StNode (current.node1->left));
            }
        }

        return tmp[i-1];
    }


    void del(node * &tree_node, int x,bool * judge)
    {
        if (tree_node==NULL) return;
        if (x<tree_node->data) del(tree_node->left,x,judge);
        if (x>tree_node->data) del(tree_node->right,x,judge);
        if (x==tree_node->data)
        {
            *judge=1;
            if (tree_node->left!=NULL&&tree_node->right!=NULL)
            {
                node *tmp=tree_node->right;
                while (tmp->left!=NULL) tmp=tmp->left;
                tree_node->data=tmp->data;
                del(tree_node->right,tree_node->data,judge);
            }
            else
            {
                node *oldNode=tree_node;
                tree_node=(tree_node->left!=NULL)?tree_node->left:tree_node->right;
                delete oldNode;
            }
        }
    }

    bool delete_one(search_tree * &tree,int x)
    {
        bool judge=0;
        del(tree->root,x,&judge);
        if (judge)
        {current_node--;return 1;}
        else
            return 0;
    }

    void delete_greater(search_tree * &tree,int x)
    {
        bool judge=0;
        int ceiling=tree->root->data;
        node *tmp=tree->root;
        while (tmp->right!=NULL)
            tmp=tmp->right;
        ceiling=tmp->data;
        do{
            judge=0;
            for (int k1 = x + 1; k1 <= ceiling; ++k1) {
                if (find(tree->root,k1)) {
                    del(tree->root, k1, &judge);
                    if (judge)
                        tree->current_node--;
                }
            }
        }
        while (judge!=0);
    }

    void delete_smaller(search_tree * &tree,int x)
    {
        bool judge=0;
        int floor=tree->root->data;
        node *tmp=tree->root;
        while (tmp->left!=NULL)
            tmp=tmp->left;
        floor=tmp->data;
        do{
            judge=0;
            for (int k1 = floor; k1 <= x - 1; ++k1) {
                if (find(tree->root,k1)) {
                    del(tree->root, k1, &judge);
                    if (judge)
                        tree->current_node--;
                }
            }
        }
        while (judge!=0);
    }

    void delete_interval(search_tree * &tree,int x1,int x2)
    {
        bool judge=0;
        do{
            judge=0;
            for (int k1 = x1+1; k1 <= x2 - 1; ++k1) {
                if (find(tree->root,k1)) {
                    del(tree->root, k1, &judge);
                    if (judge)
                        tree->current_node--;
                }
            }
        }
        while (judge!=0);
    }



    void insert(node * &tree_node,int x)
    {
        if (tree_node==NULL)
        {
            tree_node=new node(x);
            current_node++;
            return;
        }

        if (tree_node->data>=x)
        {
            insert(tree_node->left,x);
            return;
        }
        if (tree_node->data<x)

        {
            insert(tree_node->right,x);
            return;
        }
    }

    void makeEmpty(node *&tree_node)
    {
        tree_node=NULL;
        current_node=0;
//        if (tree_node==NULL) return;
//        makeEmpty(tree_node->left);
//        makeEmpty(tree_node->right);
//        delete tree_node;
    }
};


int main() {
    search_tree *tree1;
    tree1=new search_tree;

    int n;
    cin>>n;
    int input1,input2;
    char command[50];
    for (int u=0;u<n;++u)
    {
        cin>>command;
        if (strcmp(command,"insert")==0)
        {
            cin>>input1;
            tree1->insert(tree1->root,input1);
        }
        if (strcmp(command,"find")==0)
        {
            cin>>input1;
            tree1->search(tree1->root,input1);
        }
        if (strcmp(command,"find_ith")==0)
        {
            cin>>input1;
            cout<<tree1->find_ith(tree1,input1)<<endl;
        }
        if (strcmp(command,"delete")==0)
        {
            cin>>input1;
            tree1->delete_one(tree1,input1);
        }
        if (strcmp(command,"delete_greater_than")==0)
        {
            cin>>input1;
            tree1->delete_greater(tree1,input1);
        }
        if (strcmp(command,"delete_less_than")==0)
        {
            cin>>input1;
            tree1->delete_smaller(tree1,input1);
        }
        if (strcmp(command,"delete_interval")==0)
        {
            cin>>input1>>input2;
            tree1->delete_interval(tree1,input1,input2);
        }
        if (strcmp(command,"empty")==0)
        {
            tree1->makeEmpty(tree1->root);
        }
    }
    return 0;
}