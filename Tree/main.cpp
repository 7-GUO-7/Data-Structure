#include <iostream>
#include "Tree.h"
//#include <cstring>
using namespace std;
int main() {


    BinaryTree<int> tree1;
    tree1.createTree(0);
    tree1.midOrder();
    tree1.preOrder();
    tree1.postOrder();
    tree1.levelOrder();
    return 0;
}