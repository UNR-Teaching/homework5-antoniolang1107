#ifndef LINKED_BTREE
#define LINKED_BTREE

#include "TreeInterface.h"
#include "LinkedBTreeNode.h"

template<class ItemType>
class LinkedBTree: public TreeInterface<ItemType> {
private:
    LinkedBTreeNode<ItemType>* rootPtr;
public:
    LinkedBTree();

    bool isEmpty() const;
    int getHeigh() const;
    int getNumberOfNode() const;
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
}

#include LINKED_BTREE