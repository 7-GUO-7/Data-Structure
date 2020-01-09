//
// Created by GUO on 2018/11/27.
//

#ifndef TREE_CALCULATION_H
#define TREE_CALCULATION_H

#include <iostream>
using namespace std;
class calc{
public:
    enum Type {DATA,ADD,SUB,MULTI,DIV,OPAREN,CPAREN,EOL};
    struct node {
        Type type;
        int data;
        node *lchild, *rchild;

        node(Type t, int d = 0, node *lc = NULL, node *rc = NULL) {
            type = t;
            data = d;
            lchild = lc;
            rchild = rc;
        }
    };
        node *root;

        Type getToken(char *&s, int &data) //get a letter from s
        {
            char type;
            while (*s==' ') ++s;
            if (*s>='0'&&*s<='9')
            {
                data=0;
                while(*s>='0'&&*s<='9')
                {
                    data=data*10+*s-'0';
                    ++s;
                }
                return DATA;
            }
            if (*s=='\0') return EOL;

            type= *s;++s;
            switch (type)
            {
                case '+':
                    return ADD;
                case '-':
                    return SUB;
                case '*':
                    return MULTI;
                case '/':
                    return DIV;
                case '(':
                    return OPAREN;
                case ')':
                    return CPAREN;
                default:
                    return EOL;
            }
        }

        node *create(char * &s) //create a tree from s
        {
            node *p,*root=NULL;
            Type returnType;
            int value;
            while (*s)
            {
                returnType=getToken(s,value);
                switch (returnType)
                {
                case DATA:case OPAREN:
                    if (returnType==DATA) p=new node (DATA,value);
                    else p=create(s);
                    if (root!=NULL)
                        if (root->rchild==NULL) root->rchild=p;
                        else root->rchild->rchild=p;
                    break;
                case CPAREN:case EOL:
                    return root;
                case ADD: case SUB:
                    if (root==NULL) root=new node (returnType,0,p);
                    else root=new node (returnType,0,root);
                    break;
                case MULTI: case DIV:
                    if (root==NULL) root=new node (returnType,0,p);
                    else if(root->type==MULTI||root->type==DIV)
                        root=new node(returnType,0,root);
                    else root->rchild=new node (returnType,0,root->rchild);
                }

            }
            return root;
        }
        calc (char *s) {root=create(s);}
        int result()
        {
            if(root==NULL) return 0;
            return result(root);
        }

        int result(node *t)
        {
            int num1,num2;
            if (t->type==DATA) return t->data;
            num1=result(t->lchild);
            num2=result(t->rchild);
            switch (t->type)
            {
                case ADD:
                    t->data=num1+num2;break;
                case SUB:
                    t->data=num1-num2;break;
                case MULTI:
                    t->data=num1*num2;break;
                case DIV:
                    t->data=num1/num2;
            }
            return t->data;
        }



};

#endif //TREE_CALCULATION_H
