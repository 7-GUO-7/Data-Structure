#include <iostream>
#include <cstring>
using namespace std;

class Bernoulli_tree;

class tree_node{
public:

    friend Bernoulli_tree;
    tree_node** son;
    int data;
    tree_node() {
        son=new tree_node*[20];
        for (int i=0;i<20;++i)
            son[i]=NULL;
        data = 0;
    }
    tree_node(int x)
    {   son=new tree_node*[20];
        for (int i=0;i<20;++i)
            son[i]=NULL;
        data = x;

    }
};


class Bernoulli_tree
{

public:
    tree_node ** tree_pointer;
    Bernoulli_tree()
    {
        tree_pointer=new tree_node*[15];
        for (int i=0;i<15;++i)
        {
            tree_pointer[i]=NULL;
        }
    }


    ~Bernoulli_tree()
    {
        for (int i=0;i<15;++i)
        {
            delete tree_pointer[i];
        }
        delete tree_pointer;
    }

};

void union_of_tree(tree_node* &tree1,tree_node* &tree2,int digit)
{
    if (tree1->data>=tree2->data)
    {
        tree2->son[digit]=tree1;
        tree1=NULL;
    }

    else
    {
        union_of_tree(tree2,tree1,digit);
        tree2=tree1;
        tree1=NULL;
    }
}



tree_node *tmp[20000];
int count=0;

void enqueue(Bernoulli_tree &Tree, int x,int digit) {//digit from 0,add by 1 once time;
    tmp[count] = new tree_node(x);
    if (Tree.tree_pointer[digit]==NULL)
    {
        Tree.tree_pointer[digit]=tmp[count];
        return;
    }
    union_of_tree(tmp[count],Tree.tree_pointer[digit],digit);
    while(Tree.tree_pointer[digit+1]!=NULL)
    {
        union_of_tree(Tree.tree_pointer[digit],Tree.tree_pointer[digit+1],digit+1);
        digit++;
    }
    Tree.tree_pointer[digit+1]=Tree.tree_pointer[digit];
    Tree.tree_pointer[digit]=NULL;
    count++;
}

int min_(Bernoulli_tree &Tree)
{
    int min1;
    for (int i=0;i<15;++i) {
        if(Tree.tree_pointer[i]) {
            min1=Tree.tree_pointer[i]->data;
            break;
        }
    }
    for (int i=0;i<15;++i) {
        if(Tree.tree_pointer[i]) {
            if(Tree.tree_pointer[i]->data<min1)
                min1=Tree.tree_pointer[i]->data;
        }
    }
    return min1;
}

void dequeue(Bernoulli_tree &Tree)
{
    int min2,i,i2,j;
    min2=min_(Tree);
    for (i=0;i<15;++i) {
        if(Tree.tree_pointer[i]) {
            if(min2==Tree.tree_pointer[i]->data)
                break;
        }
    }
    tree_node* min_tree=Tree.tree_pointer[i];
    Tree.tree_pointer[i]=NULL;
    for ( i2=0;i2<i;++i2) {
        j=i2;
        if (!Tree.tree_pointer[j])
        {Tree.tree_pointer[j]=min_tree->son[j];continue;}//if !Tree.tree_pointer is empty, directly inserting is ok.

        union_of_tree(min_tree->son[j],Tree.tree_pointer[j],j);
        while(Tree.tree_pointer[j+1]!=NULL)
        {
            union_of_tree(Tree.tree_pointer[j],Tree.tree_pointer[j+1],j+1);
            j++;
        }
        Tree.tree_pointer[j+1]=Tree.tree_pointer[j];
        Tree.tree_pointer[j]=NULL;


    }
}


int main() {

    Bernoulli_tree Tree;


    int M;
    char input[30];
    cin >> M;
    int number;
    int min_output;
    for (int i = 0; i < M; ++i) {
        cin >> input;
        if (strcmp(input, "insert") == 0) {
            cin >> number;
            enqueue(Tree, number, 0);
        }


        if (strcmp(input, "min") == 0) {
            min_output = min_(Tree);
            cout << min_output << endl;
        }

        if (strcmp(input, "delete") == 0) {
            dequeue(Tree);
        }
    }
    return 0;
}