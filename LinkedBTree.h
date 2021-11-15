#ifndef LINKED_BTREE
#define LINKED_BTREE

#include <algorithm>
#include <iostream>
#include "TreeInterface.h"
#include "LinkedBTreeNode.h"

template<class ItemType>
class LinkedBTree: public TreeInterface<ItemType> {
private:
    LinkedBTreeNode<ItemType>* rootPtr;
public:
    LinkedBTree();

    bool isEmpty() const;
    int getHeight() const;
    int getNumberOfNodes() const;
    ItemType getRootData() const;
    bool add(const ItemType& newData);
    bool remove(const ItemType& data);
    void clear();
    ItemType getEntry(const ItemType& anEntry) const;
    bool contains(const ItemType& anEntry) const;

    void preorderTraverse(void visit(ItemType&)) const;
    void inorderTraverse(void visit(ItemType&)) const;
    void postorderTraverse(void visit(ItemType&)) const;

    ~LinkedBTree();

protected:
    int getHeightHelper(LinkedBTreeNode<ItemType>* subTreePtr) const;
    int getNumberOfNodesHelper(LinkedBTreeNode<ItemType>* subTreePtr) const;
    LinkedBTreeNode<ItemType>* balancedAdd(LinkedBTreeNode<ItemType>* subTreePtr, LinkedBTreeNode<ItemType>* newNodePtr);
    LinkedBTreeNode<ItemType>* removeValue(LinkedBTreeNode<ItemType>* subTreePtr, const ItemType target, bool& isSuccessful);
    LinkedBTreeNode<ItemType>* moveValuesUpTree(LinkedBTreeNode<ItemType>* subTreePtr);
    LinkedBTreeNode<ItemType>* findNode (LinkedBTreeNode<ItemType>* treePtr, const ItemType& target, bool& isSuccessful) const;
    LinkedBTreeNode<ItemType>* copyTree (const LinkedBTreeNode<ItemType>* oldTreeRootPtr) const;
    void destroyTree(LinkedBTreeNode<ItemType>* subTreePtr);
    void preorder(void visit(ItemType&), LinkedBTreeNode<ItemType>* treePtr) const;
    void inorder(void visit(ItemType&), LinkedBTreeNode<ItemType>* treePtr) const;
    void postorder(void visit(ItemType&), LinkedBTreeNode<ItemType>* treePtr) const;
    void visit(ItemType& value);
};

#include "LinkedBTree.cpp"
#endif