#ifndef LINKED_BTREE_NODE
#define LINKED_BTREE_NODE

template<class ItemType>
class LinkedBTreeNode {
private:
    ItemType item;
    Node<ItemType>* leftChildPtr;
    Node<ItemType>* rightChildPtr;

public:
    LinkedBTreeNode();
    LinkedBTreeNode(const ItemType& newData, Node<ItemType>* left, Node<ItemType>* right);
    void setItem(const ItemType& newData);
    ItemType getItem() const;

    bool isLeaf() const;

    Node<ItemType>* getLeftChildPtr() const;
    Node<ItemType>* getRightChildPtr() const;

    void setLeftChildPtr(Node<ItemType>* newLeftChildPtr);
    void setRightChildPtr(Node<ItemType>* newRightChildPtr);
};

#include "LinkedBTreeNode.cpp"
#endif