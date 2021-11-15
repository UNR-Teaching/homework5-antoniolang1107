#include <random>
#include "LinkedBTreeNode.h"
#include "LinkedBTree.h"

int main() {
    int values[200], randomizedValues[100];
    for (int i = 1; i <= 200; i++) {
        values[i-1] = i;
    }
    for (int i = 0; i < 100; i++) {
        randomizedValues[i] = rand() % 200;
    }

    LinkedBTree<int> testBTree;
    int x = 5;
    testBTree.add(x);
    // make arr with values [1-200]
    // make arr[100] with values from original arr
    // add data into binary search tree
    // output height (# of nodes)
    // output inorder, preorder, postorder


    return 0;
}