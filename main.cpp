#include <random>
#include <iostream>
#include "LinkedBTreeNode.h"
#include "LinkedBTree.h"
#include "LinkedBSearchTree.h"

void display(int tempInt);

int main() {
    LinkedBSearchTree<int> BSTree;
    int values[200], randomizedValues[100];
    
    for (int i = 1; i <= 200; i++) {
        values[i-1] = i;
    }
    for (int i = 0; i < 100; i++) {
        randomizedValues[i] = values[rand() % 200];
        BSTree.add(randomizedValues[i]);
    }

    

    std::cout << "Height of the tree: " << BSTree.getHeight() << std::endl;
    std::cout << "Preorder output: " << std::endl << std::endl;
    BSTree.preorderTraverse(display());
    std::cout << "Inorder output: " << std::endl << std::endl;;
    BSTree.inorderTraverse(display());
    std::cout << "Postorder output: " << std::endl;
    BSTree.postorderTraverse(display());

    return 0;
}

void display(int tempInt) {
    std::cout << tempInt << std::endl;
}